#include "types.h"

#ifndef GAME_PIECE
#define GAME_PIECE

SquareNode getLegalMoves(State state, Piece piece);
struct coord coordFromPiece(Piece piece);
void moveSelectedPiece(State state, struct coord dest);
SquareNode getAttackedSquares(State state);

#endif