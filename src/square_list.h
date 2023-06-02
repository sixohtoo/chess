#include "types.h"

#ifndef GAME_SQUARE_LIST
#define GAME_SQUARE_LIST

typedef struct square_node
{
    struct square_node *next;
    Square square;
} *SquareNode;

typedef struct square_list
{
    SquareNode head;
} *SquareList;

SquareList initSquareList();
SquareList addSquare(SquareList list, Square square);
SquareList removeSquare(SquareList list, Square square);
void freeSquareList(SquareList list);
#endif