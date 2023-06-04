#include <SDL2/SDL.h>

#ifndef GAME_TYPES
#define GAME_TYPES

#include "constants.h"

typedef struct square *Square;
typedef struct piece *Piece;

enum PieceType
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    NONE,
};

enum Colour
{
    WHITE,
    BLACK
};

struct square
{
    int row;
    int col;
    enum Colour colour;
    int coord_x;
    int coord_y;
    Piece piece;
};

struct piece
{
    int row;
    int col;
    // int coord_x;
    // int coord_y;
    enum Colour colour;
    enum PieceType type;
    int moved;
    SDL_Rect *img;
    Square square;
};

typedef struct piece_node
{
    struct piece_node *next;
    Piece piece;
} *PieceNode;

typedef struct piece_list
{
    PieceNode head;
} *PieceList;

typedef struct square_node
{
    struct square_node *next;
    Square square;
} *SquareNode;

typedef struct square_list
{
    SquareNode head;
} *SquareList;

typedef Square **Board;

typedef struct state
{
    Board board;
    int turn;
    enum Colour playerTurn;
    PieceList pieces;
    Piece selected;
} *State;

typedef struct app
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    State state;
} *App;

typedef struct coord
{
    int x;
    int y;
} *Coord;

Piece createPiece(int row, int col, char c, SDL_Rect *img, Square square);
Square createSquare(int row, int col);
enum PieceType getPiece(char c);
enum Colour getColour(char c);

#endif