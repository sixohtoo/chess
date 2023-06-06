#include "piece.h"
#include "square_list.h"
#include "utils.h"

void pawnMoves(App app);
void rookMoves(App app);
void knightMoves(App app);
void bishopMoves(App app);
void queenMoves(App app);
void kingMoves(App app);

/*
Still need to code
stopping at pieces
check
en passant
castling

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

void getLegalMoves(App app)
{
    if (app->state->playerTurn != app->state->selected->colour)
        return;
    switch (app->state->displaying->type)
    {
    case PAWN:
        pawnMoves(app);
        break;
    case ROOK:
        rookMoves(app);
        break;
    case KNIGHT:
        knightMoves(app);
        break;
    case BISHOP:
        bishopMoves(app);
        break;
    case QUEEN:
        queenMoves(app);
        break;
    case KING:
        kingMoves(app);
        break;
    default:
        break;
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

void pawnMoves(App app)
{
    Piece piece = app->state->selected;
    struct coord dirs[2] =
        {
            {(piece->colour * 1.0 - 0.5) * 2, 0},
            {(piece->colour * 1.0 - 0.5) * 2 * (!piece->moves + 1), 0}}; // double move on first move case
    struct coord c = {
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 2; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
        }
    }
}

void rookMoves(App app)
{
    struct coord dirs[4] = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1}};
    struct coord c = {
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 4; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
}

void knightMoves(App app)
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
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
        }
    }
}

void bishopMoves(App app)
{
    struct coord dirs[4] = {
        {-1, 1},
        {1, 1},
        {1, -1},
        {-1, -1}};
    struct coord c = {
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 4; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
}

void queenMoves(App app)
{
    struct coord c = {
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir = {
            c.x + dir.x,
            c.y + dir.y};
        while (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
            newDir.x += dir.x;
            newDir.y += dir.y;
        }
    }
}

void kingMoves(App app)
{
    struct coord c = {
        app->state->selected->row,
        app->state->selected->col};
    for (int i = 0; i < 8; i++)
    {
        struct coord dir = dirs[i];
        struct coord newDir =
            {
                c.x + dir.x,
                c.y + dir.y};
        if (isValidGridCoord(newDir))
        {
            Square square = getSquareFromCoord(app, newDir);
            app->state->displayedSquares = addSquare(app->state->displayedSquares, square);
        }
    }
}

void moveSelectedPiece(App app, struct coord dest)
{
    Piece selected = app->state->selected;
    selected->square->piece = 0; // NULL makes linter unhappy. whatever.
    Square dest_square = app->state->board[dest.x][dest.y];
    selected->square = dest_square;
    dest_square->piece = selected;
    selected->row = dest.x;
    selected->col = dest.y;
    selected->img_dest->x = dest_square->coord_x;
    selected->img_dest->y = dest_square->coord_y;
    app->state->displaying = 0;
    selected->moves += 1;
    if (!app->state->playerTurn)
        app->state->turn += 1;
    app->state->playerTurn = !app->state->playerTurn;
    app->state->displayedSquares = clearSquareList(app->state->displayedSquares);
}

PieceNode getAttackedSquares(State state)
{
    enum Colour attackPlayer = !state->playerTurn;
    // for
    return 0;
}