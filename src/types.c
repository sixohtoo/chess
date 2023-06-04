#include "types.h"
#include "constants.h"
#include "utils.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

enum PieceType getPiece(char c)
{
    switch (toLower(c))
    {
    case 'p':
        return PAWN;
    case 'r':
        return ROOK;
    case 'n':
        return KNIGHT;
    case 'b':
        return BISHOP;
    case 'q':
        return QUEEN;
    case 'k':
        return KING;
    default:
        return NONE;
    }
}

enum Colour getColour(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return WHITE;
    }
    return BLACK;
}

Piece createPiece(int row, int col, char c, SDL_Rect *img, Square square)
{
    Piece piece = malloc(sizeof(struct piece));
    piece->row = row;
    piece->col = col;
    piece->type = getPiece(c);
    piece->colour = getColour(c);
    piece->moved = 0;
    piece->img = img;
    piece->square = square;
    square->piece = piece;
    return piece;
}

Square createSquare(int row, int col)
{
    Square square = malloc(sizeof(struct square));
    square->row = row;
    square->col = col;
    square->coord_x = CHESS_BOARD_BORDER + row * CHESS_SQUARE_SIZE + CHESS_SQUARE_SIZE / 6;
    square->coord_y = CHESS_BOARD_BORDER + col * CHESS_SQUARE_SIZE + CHESS_SQUARE_SIZE / 6;
    square->colour = (row + col) % 2 ? BLACK : WHITE;
    square->piece = NULL;
    return square;
}