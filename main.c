#include <ncurses.h>

#include "board.h"
#include "draw.h"
#include "move.h"

int main(int argc, char ** argv) {
	init_ncurses();

	Board board;

	for (int row = 0; row < 20; row++)
	for (int col = 0; col < 10; col++)
        board.board[row][col] = EMPTY;

    board.piece = I;
    board.rotation = 0;
    board.piece_point.x = 5;
    board.piece_point.y = 0;

    while (1) {
		draw(&board);
		switch(getch()) {
			case 'q':
				goto quit;
            case 'a':
                move_piece(&board, LEFT);
                break;
            case 'o':
                move_piece(&board, RIGHT);
                break;
            case 'e':
                hard_drop(&board);
                break;
		}
	}
quit:
    endwin();
	return 0;
}
