#include <ncurses.h>

#include "board.h"
#include "draw.h"

int main(int argc, char ** argv) {
	init_ncurses();

    Board board;

	for (int row = 0; row < 20; row++)
	for (int col = 0; col < 10; col++)
        board.board[row][col] = EMPTY;

    board.board[19][4] = CYAN;

	while (1) {
		draw(&board);
		switch(getch()) {
			case 'q':
				goto quit;
		}
	}
quit:
    endwin();
	return 0;
}
