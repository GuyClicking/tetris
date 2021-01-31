LIBS=-lncurses -ltinfo

FUNNYFLAGS=-DCOL_256 -DHOLD -DSRS -DSEVEN_BAG

SRC=*.c
EXE=tetris

all: ${SRC}
	${CC} ${SRC} ${FUNNYFLAGS} -o ${EXE} ${LIBS}
