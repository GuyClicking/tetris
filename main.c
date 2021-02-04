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

	board.bag_left = 0;

	init_queue(&board);

	next_piece(&board);
	board.rotation = 0;
	board.piece_point.x = 5;
	board.piece_point.y = 0;

	while (1) {
		draw(&board);
		switch(getch()) {
			case 'q':
				goto quit;
			case 'h':
				move_piece(&board, LEFT);
				break;
			case 'k':
				move_piece(&board, RIGHT);
				break;
			case 's':
				rotate_piece(&board, LEFT);
				break;
			case 'd':
				rotate_piece(&board, RIGHT);
				break;
			case 'j':
				hard_drop(&board);
				break;
		}
	}
quit:
	endwin();
	printf("%d\n",board.piece);
	for (int i = 0; i < 5; i++)
		printf("%d\n",board.queue[(board.queue_index+i)%5]);
	return 0;
}
