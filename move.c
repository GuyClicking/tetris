#include "board.h"
#include "move.h"

int collision(Board *board) {
	int i;

	for (i = 0; i < 4; i++) {
		Point offset = location_map[board->piece][board->rotation][i];
		char x = board->piece_point.x - offset.x,
			 y = board->piece_point.y - offset.y;
		if  (x < 0 || x >= 10 ||
			(y > 0 && board->board[x][y] != NONE)) return 1;
	}
	
	return 0;
}

int move_piece(Board *board, Direction dir) {
	const int table[2] = {-1,1};
	board->piece_point.x += table[dir];
	if (collision(board)) {
		board->piece_point.x -= table[dir];
		return 1;
	}
	return 0;
}

void hard_drop(Board *board) {
	int i;

	while (!collision(board)) {
		board->piece_point.y++;
	}
	board->piece_point.y--;
	for (i = 0; i < 4; i++) {
		Point offset = location_map[board->piece][board->rotation][i];
		char x = board->piece_point.x - offset.x,
			 y = board->piece_point.y - offset.y;
		board->board[x][y] = (Mino)board->piece;
	}
}
