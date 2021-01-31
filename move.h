#pragma once

#include "board.h"

typedef enum {
    LEFT, RIGHT
} Direction;

int move_piece(Board *board, Direction dir);
void hard_drop(Board *board);
