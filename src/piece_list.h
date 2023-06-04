
#ifndef GAME_PIECE_LIST
#define GAME_PIECE_LIST

#include "types.h"

PieceList initPieceList();
PieceList addPiece(PieceList list, Piece piece);
PieceList removePiece(PieceList list, Piece piece);
void freePieceList(PieceList list);
#endif