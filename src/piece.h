#include "types.h"

#ifndef GAME_PIECE
#define GAME_PIECE

void getLegalMoves(App app);
struct coord coordFromPiece(Piece piece);
void moveSelectedPiece(App app, struct coord dest);
PieceNode getAttackedSquares(State state);

#endif