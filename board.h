#pragma once

#include <stdbool.h>

typedef enum {
	NONE, I, O, T, J, L, S, Z
} Piece;

typedef enum {
	EMPTY, CYAN, YELLOW, PURPLE, BLUE, ORANGE, GREEN, RED, GREY
} Mino;

typedef struct {
	char x,y;
} Point;

typedef struct {
	Mino board[20][10];
	// ring buffer!
	Piece queue[5];
	int queue_index;
	Piece piece;
	Point piece_point;
	char rotation;
#ifdef HOLD
	Piece hold;
#endif
#ifdef SEVEN_BAG
	bool bag[7];
	int bag_left;
#endif
} Board;

static const Point location_map[8][4][4] = {
	{}, // No piece
	{ // I
	{{-1,0},{0,0},{1,0},{2,0}},
	{{0,-1},{0,0},{0,1},{0,2}},
	{{-2,0},{-1,0},{0,0},{1,0}},
	{{0,-2},{0,-1},{0,0},{0,1}}
	}, { // O
	{{0,0},{0,1},{1,0},{1,1}},
	{{0,0},{0,1},{1,0},{1,1}},
	{{0,0},{0,1},{1,0},{1,1}},
	{{0,0},{0,1},{1,0},{1,1}}
	}, { // T
	{{0,0},{-1,0},{1,0},{0,1}},
	{{0,0},{0,-1},{1,0},{0,1}},
	{{0,0},{-1,0},{1,0},{0,-1}},
	{{0,0},{-1,0},{0,-1},{0,1}}
	}, { // J
	{{-1,0},{0,0},{1,0},{1,1}},
	{{-1,1},{0,1},{0,0},{0,-1}},
	{{-1,-1},{-1,0},{0,0},{1,0}},
	{{1,-1},{0,-1},{0,0},{0,1}}
	}, { // L
	{{-1,0},{0,0},{1,0},{-1,1}},
	{{-1,-1},{0,-1},{0,0},{0,1}},
	{{1,-1},{-1,0},{0,0},{1,0}},
	{{1,1},{0,1},{0,0},{0,-1}}
	}, { // S
	{{-1,1},{0,1},{0,0},{1,0}},
	{{1,1},{1,0},{0,0},{0,-1}},
	{{-1,0},{0,0},{0,-1},{1,-1}},
	{{0,1},{0,0},{-1,0},{-1,-1}}
	}, { // Z
	{{1,1},{0,1},{0,0},{-1,0}},
	{{-1,1},{-1,0},{0,0},{0,-1}},
	{{1,0},{0,0},{0,-1},{-1,-1}},
	{{0,1},{0,0},{1,0},{1,-1}}
	}
};

