#include <SDL2/SDL.h>

#ifndef GAME_TYPES
#define GAME_TYPES

#include "constants.h"

typedef struct square *Square;
typedef struct piece *Piece;

enum PieceType
{
    QUEEN,
    KING,
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN,
    NONE,
};

enum Colour
{
    BLACK,
    WHITE
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
    int row;             // row in 2d array
    int col;             // col in 2d array
    enum Colour colour;  // colour (white or black)
    enum PieceType type; // type of piece
    int moved;           // has moved (for castling)
    Square square;       // Square piece is on
    SDL_Texture *img;    // image texture
    SDL_Rect *img_src;   // image position on spirte
    SDL_Rect *img_dest;  // image position on window
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

Piece createPiece(int row, int col, char c, SDL_Rect *img_dest, SDL_Texture *img, Square square);
Square createSquare(int row, int col);
enum PieceType getPiece(char c);
enum Colour getColour(char c);

#endif