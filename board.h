#pragma once

typedef enum {
    NONE, I, O, T, J, L, S, Z
} Piece;

typedef enum {
    EMPTY, CYAN, YELLOW, PURPLE, BLUE, ORANGE, GREEN, RED, GREY
} Mino;

typedef struct {
    Mino board[20][10];
    Piece preview[5];
    int preview_pntr;
    Piece piece;
#ifdef HOLD
    Piece hold;
#endif
#ifdef SEVEN_BAG
    Piece bag[7];
#endif
} Board;
