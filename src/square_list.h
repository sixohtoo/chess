#ifndef GAME_SQUARE_LIST
#define GAME_SQUARE_LIST

#include "types.h"

// SquareList initSquareList();
SquareNode addSquare(SquareNode list, Square square);
SquareNode clearSquareList(SquareNode list);
SquareNode removeSquare(SquareNode list, Square square);
void freeSquareList(SquareNode list);
int containsSquareList(SquareNode list, struct coord c);
#endif