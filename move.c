#include <stdlib.h>

#include "board.h"
#include "move.h"

void init_queue(Board *board) {
	// bad code
	int i,n;
	for (i = 0; i < 5; i++) {
		board->queue_index %= 5;
		if (board->bag_left <= 0) {
			int j;
			for (j = 0; j < 7; j++)
				board->bag[j]=1;
			n = rand()%7;
			board->bag[n] = 0;
			board->queue[i] = n + 1;
			board->queue_index++;
			board->bag_left = 6;
			continue;
		}
		do {
			n = rand() % 7;
		} while (!board->bag[n]);
		board->bag[n] = 0;
		board->queue[i] = n+1;
		board->bag_left--;
		board->queue_index++;
	}
}

void next_piece(Board *board) {
	if (board->bag_left == 0) {
		int i,n;
		for (i = 0; i < 7; i++)
			board->bag[i]=1;
		n = rand()%7;
		board->bag[n] = 0;
		board->piece = board->queue[board->queue_index];
		board->queue[board->queue_index++] = n + 1;
		board->queue_index %= 5;
		board->bag_left = 6;
		return;
	}
	int n;
	do {
		n = rand() % 7;
	} while (!board->bag[n]);
	board->bag[n] = 0;
	board->piece = board->queue[board->queue_index];
	board->queue[board->queue_index++] = n + 1;
	board->queue_index %= 5;
	board->bag_left--;
}

int collision(Board *board) {
	int i;

	for (i = 0; i < 4; i++) {
		Point offset = location_map[board->piece][board->rotation][i];
		char x = board->piece_point.x - offset.x,
			 y = board->piece_point.y - offset.y;
		if  (x < 0 || x >= 10 || y >= 20 ||
			(y > 0 && board->board[y][x] != NONE)) return 1;
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
		board->board[y][x] = (Mino)board->piece;
	}
	next_piece(board);
	board->rotation = 0;
	board->piece_point.x = 5;
	board->piece_point.y = 0;
}
