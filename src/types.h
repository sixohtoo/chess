#include <SDL2/SDL.h>
#include "constants.h"

#ifndef GAME_TYPES
#define GAME_TYPES

typedef struct app
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} *App;

enum PieceType
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum Colour
{
    WHITE,
    BLACK
};

typedef struct piece
{
    int row;
    int col;
    enum Colour colour;
    enum PieceType type;
    int moved;
} *Piece;

typedef struct square
{
    int row;
    int col;
    enum Colour colour;
    int coord_x;
    int coord_y;
} *Square;

typedef Square **Board;

typedef struct state
{
    Board board;
    int turn;
    enum Colour playerTurn;
} *State;

Piece createPiece(int row, int col, enum PieceType type, enum Colour colour);
Square createSquare(int row, int col, int coord_x, int coord_y, enum Colour colour);
#endif