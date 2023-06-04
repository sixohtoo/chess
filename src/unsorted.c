#include "unsorted.h"
#include "types.h"

void moveSelectedPiece(App app, struct coord dest)
{
    Piece selected = app->state->selected;
    selected->square->piece = NULL;
    Square dest_square = app->state->board[dest.x][dest.y];
    selected->square = dest_square;
    dest_square->piece = selected;
    selected->img->x = dest_square->coord_x;
    selected->img->y = dest_square->coord_y;
}