
#ifndef GAME_PIECE_LIST
#define GAME_PIECE_LIST

#include "types.h"

// PieceList initPieceList();
PieceNode addPiece(PieceNode list, Piece piece);
PieceNode removePiece(PieceNode list, Piece piece);
void freePieceList(PieceNode list);
#endif