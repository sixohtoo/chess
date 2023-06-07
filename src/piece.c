#include "piece.h"
#include "square_list.h"
#include "utils.h"

SquareNode pawnMoves(State state, Piece piece);
SquareNode rookMoves(State state, Piece piece);
SquareNode knightMoves(State state, Piece piece);
SquareNode bishopMoves(State state, Piece piece);
SquareNode queenMoves(State state, Piece piece);
SquareNode kingMoves(State state, Piece piece, int all);
SquareNode kingMovesCastle(State state, Piece piece);
int isEmptySquare(State state, SquareNode list, Square square);

/*
Still need to code
TODO: save legal moves in piece to avoid calculating multiple times
check ??
pawn taking
en passant
castling
promoting
*/

struct coord dirs[8] = {
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1}};

SquareNode getLegalMoves(State state, Piece piece, int castling)
{
    // if (state->playerTurn != piece->colour) // will have to change this eventually
    //     return NULL;
    printPieceType(piece);
    switch (piece->type)
    {
    case PAWN:
        return pawnMoves(state, piece);
        break;
    case ROOK:
        return rookMoves(state, piece);
        break;
    case KNIGHT:
        return knightMoves(state, piece);
        break;
    case BISHOP:
        return bishopMoves(state, piece);
        break;
    case QUEEN:
        return queenMoves(state, piece);
        break;
    case KING:
        return kingMoves(state, piece, castling);
        break;
    default:
        return NULL;
    }
}

struct coord coordFromPiece(Piece piece)
{
    struct coord c = {
        piece->row,
        piece->col};
    return c;
}

int isValidGridCoord(struct coord c)
{
    return c.x >= 0 && c.x < NUM_SQUARES_ROW && c.y >= 0 && c.y < NUM_SQUARES_ROW;
}

SquareNode pawnMoves(State state, Piece piece)
{
    // Piece piece = state->selected;
    SquareNode squares = NULL;
    struct coord dirs[2] =
        {
            {(piece->colour * 1.0 - 0.5) * 2, 0},
            {(piece->colour * 1.0 - 0.5) * 2 * (!piece->moves + 1), 0}}; // double move on first move case
    struct coord c = {
        piece->row,
        piece->col};
    for (int i = 0; i < 2; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir) && isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            squares = addSquare(squares, square);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
        }
    }
    return squares;
}

SquareNode rookMoves(State state, Piece piece)
{
    struct coord dirs[4] = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1}};
    struct coord c = {
        piece->row,
        piece->col};
    SquareNode squares = NULL;
    for (int i = 0; i < 4; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir) && isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            squares = addSquare(squares, square);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
    return squares;
}

SquareNode knightMoves(State state, Piece piece)
{
    struct coord dirs[8] = {
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1, 2}};

    struct coord c = {
        piece->row,
        piece->col};
    SquareNode squares = NULL;
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir) && isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            squares = addSquare(squares, square);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
        }
    }
    return squares;
}

SquareNode bishopMoves(State state, Piece piece)
{
    struct coord dirs[4] = {
        {-1, 1},
        {1, 1},
        {1, -1},
        {-1, -1}};
    struct coord c = {
        piece->row,
        piece->col};
    SquareNode squares = NULL;
    for (int i = 0; i < 4; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir) && isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            squares = addSquare(squares, square);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
    return squares;
}

SquareNode queenMoves(State state, Piece piece)
{
    struct coord c = {
        piece->row,
        piece->col};
    SquareNode squares = NULL;
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir) && isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            squares = addSquare(squares, square);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
    return squares;
}

SquareNode kingMoves(State state, Piece piece, int castling)
{
    struct coord c = {
        piece->row,
        piece->col};
    SquareNode squares = NULL;
    SquareNode illegal = getAttackedSquares(state);
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir) &&
            isEmptySquare(state, squares, getSquareFromCoord(state->board, newDir)) &&
            !containsSquareList(illegal, newDir))
        {
            Square square = getSquareFromCoord(state->board, newDir);
            // state->displayedSquares = addSquare(state->displayedSquares, square);
            squares = addSquare(squares, square);
        }
    }
    if (castling)
    {
        squares = combineSquareList(squares, kingMovesCastle(state, piece));
    }
    return squares;
}

SquareNode kingMovesCastle(State state, Piece piece)
{
    return NULL;
}

void moveSelectedPiece(State state, struct coord dest)
{
    Piece selected = state->selected;
    selected->square->piece = 0; // NULL makes linter unhappy. whatever.
    Square dest_square = state->board[dest.x][dest.y];
    selected->square = dest_square;
    dest_square->piece = selected;
    selected->row = dest.x;
    selected->col = dest.y;
    selected->img_dest->x = dest_square->coord_x;
    selected->img_dest->y = dest_square->coord_y;
    state->displaying = 0;
    selected->moves += 1;
    if (!state->playerTurn)
        state->turn += 1;
    state->playerTurn = !state->playerTurn;
    state->displayedSquares = clearSquareList(state->displayedSquares);
}

SquareNode getAttackedSquares(State state)
{
    enum Colour attackPlayer = !state->playerTurn;
    PieceNode curr = state->pieces;
    SquareNode squares = 0;
    while (curr != 0)
    {
        if (curr->piece->colour != attackPlayer)
        {
            curr = curr->next;
            continue;
        }
        squares = combineSquareList(squares, getLegalMoves(state, curr->piece, 0));
        curr = curr->next;
    }
    return squares;
}

int isEmptySquare(State state, SquareNode list, Square square)
{
    if (!square->piece)
        return 1;
    if (square->piece->colour != state->playerTurn)
    {
        addSquare(list, square);
    }
    return 0;
}