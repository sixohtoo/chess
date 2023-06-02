#include "types.h"
#include <stdlib.h>

Piece createPiece(int row, int col, enum PieceType type, enum Colour colour)
{
    Piece piece = malloc(sizeof(struct piece));
    piece->row = row;
    piece->col = col;
    piece->type = type;
    piece->colour = colour;
    piece->moved = 0;
    return piece;
}

Square createSquare(int row, int col, int coord_x, int coord_y, enum Colour colour)
{
    Square square = malloc(sizeof(struct square));
    square->row = row;
    square->col = col;
    square->coord_x = coord_x;
    square->coord_y = coord_y;
    square->colour = colour;
    return square;
}