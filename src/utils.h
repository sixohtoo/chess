#include "types.h"

#ifndef GAME_UTILS
#define GAME_UTILS
struct coord square_num_to_coord(int num);
int isValidCoord(struct coord c);
char toLower(char c);
struct coord coord_to_grid(struct coord c);
Piece piece_from_coord(Board board, struct coord c);
void printPieceType(Piece piece);
Square getSquareFromCoord(App app, struct coord c);
int coordEqual(struct coord a, struct coord b);
#endif