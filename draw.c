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
	init_pair(CYAN,    COLOR_BLACK,   14);
	init_pair(YELLOW,  COLOR_BLACK,   11);
	init_pair(PURPLE,  COLOR_BLACK,   5);
	init_pair(BLUE,    COLOR_BLACK,   12);
	init_pair(ORANGE,  COLOR_BLACK,   166);
	init_pair(GREEN,   COLOR_BLACK,   10);
	init_pair(RED,     COLOR_BLACK,   9);
	init_pair(GREY,    COLOR_BLACK,   8);
#elif defined COL_8
	init_pair(CYAN,    COLOR_BLACK,   COLOR_CYAN);
	init_pair(YELLOW,  COLOR_BLACK,   COLOR_YELLOW);
	init_pair(PURPLE,  COLOR_BLACK,   COLOR_MAGENTA);
	init_pair(BLUE,    COLOR_BLACK,   COLOR_BLUE);
	init_pair(GREEN,   COLOR_BLACK,   COLOR_GREEN);
	init_pair(RED,     COLOR_BLACK,   COLOR_RED);
	// there is no orange for 8 colour
	init_pair(ORANGE,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(GREY,    COLOR_BLACK,   COLOR_WHITE);
#endif
}

void draw(Board *board) {
	int row,col;
	for (row = 0; row < 20; row++)
	for (col = 0; col < 10; col++) {
		if (board->board[row][col] != EMPTY)
			attron(COLOR_PAIR(board->board[row][col]));

		mvaddch(row + (LINES/2 - 20/2), col + (COLS/2 - 10/2), ' ');

		if (board->board[row][col] != EMPTY)
			attroff(COLOR_PAIR(board->board[row][col]));
	}

	refresh();
}
