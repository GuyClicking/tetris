#include <locale.h>
#include <ncurses.h>

#include "board.h"

void init_ncurses() {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	curs_set(0);

	start_color();
#ifdef COL_256
	init_pair(CYAN,	COLOR_BLACK,   14);
	init_pair(YELLOW,  COLOR_BLACK,   11);
	init_pair(PURPLE,  COLOR_BLACK,   5);
	init_pair(BLUE,	COLOR_BLACK,   12);
	init_pair(ORANGE,  COLOR_BLACK,   166);
	init_pair(GREEN,   COLOR_BLACK,   10);
	init_pair(RED,	   COLOR_BLACK,   9);
	init_pair(GREY,	COLOR_BLACK,   8);
#elif defined COL_8
	init_pair(CYAN,	COLOR_BLACK,   COLOR_CYAN);
	init_pair(YELLOW,  COLOR_BLACK,   COLOR_YELLOW);
	init_pair(PURPLE,  COLOR_BLACK,   COLOR_MAGENTA);
	init_pair(BLUE,	COLOR_BLACK,   COLOR_BLUE);
	init_pair(GREEN,   COLOR_BLACK,   COLOR_GREEN);
	init_pair(RED,	   COLOR_BLACK,   COLOR_RED);
	// there is no orange for 8 colour
	init_pair(ORANGE,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(GREY,	COLOR_BLACK,   COLOR_WHITE);
#else
	init_pair(CYAN,	COLOR_BLACK,   COLOR_WHITE);
	init_pair(YELLOW,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(PURPLE,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(BLUE,	COLOR_BLACK,   COLOR_WHITE);
	init_pair(ORANGE,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(GREEN,   COLOR_BLACK,   COLOR_WHITE);
	init_pair(RED,	   COLOR_BLACK,   COLOR_WHITE);
	init_pair(GREY,	COLOR_BLACK,   COLOR_WHITE);
#endif

	int row,col,i;
	attron(COLOR_PAIR(GREY));
	for (row = 0; row < 20; row++) {
	mvprintw(row + (LINES/2 - 20/2), -1*2 + (COLS/2 - 10), "  ");
	mvprintw(row + (LINES/2 - 20/2), 10*2 + (COLS/2 - 10), "  ");
	}
	for (col = -1; col < 11; col++) {
	mvprintw(20 + (LINES/2 - 20/2), col*2 + (COLS/2 - 10), "  ");
	}
	attroff(COLOR_PAIR(GREY));
}

void draw(Board *board) {
	int row,col,i,j;
	for (row = -2; row < 20; row++)
	for (col = 0; col < 10; col++) {
		if (row > 0 && board->board[row][col] != EMPTY)
			attron(COLOR_PAIR(board->board[row][col]));

		mvprintw(row + (LINES/2 - 20/2), col*2 + (COLS/2 - 10), "  ");

		if (board->board[row][col] != EMPTY)
			attroff(COLOR_PAIR(board->board[row][col]));
	}

	attron(COLOR_PAIR(board->piece));

	for (i = 0; i < 4; i++) {
		Point offset = location_map[board->piece][board->rotation][i];
		char x = board->piece_point.x - offset.x,
			 y = board->piece_point.y - offset.y;
		mvprintw(y + (LINES/2 - 20/2), x*2 + (COLS/2 - 10), "  ");
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			Piece p = board->queue[(board->queue_index + i)%5];
			Point offset = location_map[p][0][j];
			char x = offset.x,
				 y = offset.y;
			mvprintw(y + (i*4) + (LINES/2 - 20/2), x*2 + 24 + (COLS/2 - 10), "  ");
		}
	}
	attroff(COLOR_PAIR(board->piece));

	refresh();
}
