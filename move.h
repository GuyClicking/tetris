#pragma once

#include "board.h"

typedef enum {
    LEFT, RIGHT
} Direction;

void init_queue(Board *board);
void next_piece(Board *board);
int move_piece(Board *board, Direction dir);
void hard_drop(Board *board);
