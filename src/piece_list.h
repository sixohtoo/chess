#include "types.h"

#ifndef GAME_PIECE_LIST
#define GAME_PIECE_LIST

typedef struct piece_node
{
    struct piece_node *next;
    Piece piece;
} *PieceNode;

typedef struct piece_list
{
    PieceNode head;
} *PieceList;

PieceList initPieceList();
PieceList addPiece(PieceList list, Piece piece);
PieceList removePiece(PieceList list, Piece piece);
void freePieceList(PieceList list);
#endif