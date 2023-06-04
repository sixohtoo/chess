#ifndef GAME_SQUARE_LIST
#define GAME_SQUARE_LIST

#include "types.h"

SquareList initSquareList();
SquareList addSquare(SquareList list, Square square);
SquareList removeSquare(SquareList list, Square square);
void freeSquareList(SquareList list);
#endif