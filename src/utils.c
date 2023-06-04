#include "utils.h"
#include "constants.h"

struct coord square_num_to_coord(int num)
{
    struct coord c = {num % 8, num / 8};
    return c;
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}

struct coord coord_to_grid(struct coord c)
{
    float x = (c.x * 1.0 - CHESS_BOARD_BORDER) / (CHESS_SQUARE_SIZE);
    float y = (c.y * 1.0 - CHESS_BOARD_BORDER) / (CHESS_SQUARE_SIZE);
    struct coord ret =
        {
            x >= 0 && x < NUM_SQUARES_ROW ? x : INVALID_COORD,
            y >= 0 && y < NUM_SQUARES_ROW ? y : INVALID_COORD};
    return ret;
}

int isValidCoord(struct coord c)
{
    return (c.x != INVALID_COORD && c.y != INVALID_COORD);
}

Piece piece_from_coord(Board board, struct coord c)
{
    return board[c.x][c.y]->piece;
}

void printPieceType(Piece piece)
{
    if (piece == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    switch (piece->type)
    {
    case PAWN:
        printf("PAWN\n");
        break;
    case ROOK:
        printf("ROOK\n");
        break;
    case KNIGHT:
        printf("KNIGHT\n");
        break;
    case BISHOP:
        printf("BISHOP\n");
        break;
    case QUEEN:
        printf("QUEEN\n");
        break;
    case KING:
        printf("KING\n");
        break;
    default:
        printf("EMPTY");
        break;
    }
}