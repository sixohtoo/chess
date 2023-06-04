#include <SDL2/SDL.h>
#include "types.h"
#include "utils.h"
#include "unsorted.h"

void mouseDownInput(App app, SDL_MouseButtonEvent e);
void mouseUpInput(App app, SDL_MouseButtonEvent e);
void mouseMotionInput(App app, SDL_Event e);

void doInput(App app)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(EXIT_SUCCESS);
            break;
        case SDL_MOUSEBUTTONDOWN:
            printf("click!\n");
            mouseDownInput(app, event.button);
            break;
        case SDL_MOUSEBUTTONUP:
            printf("released!\n");
            mouseUpInput(app, event.button);
            break;
        case SDL_MOUSEMOTION:
            mouseMotionInput(app, event);
            break;
        default:
            break;
        }
    }
}

void mouseDownInput(App app, SDL_MouseButtonEvent e)
{
    if (e.button == SDL_BUTTON_LEFT)
    {
        struct coord pointer = {e.x, e.y};
        struct coord grid = coord_to_grid(pointer);

        Piece piece = piece_from_coord(app->state->board, grid);
        printPieceType(piece);
        if (piece == NULL)
        {
            return;
        }

        app->state->selected = piece;
        printf("Selected piece");
    }
}

void mouseUpInput(App app, SDL_MouseButtonEvent e)
{
    Piece selected = app->state->selected;
    if (e.button == SDL_BUTTON_LEFT && selected != NULL)
    {
        struct coord pointer = {e.x, e.y};
        struct coord grid = coord_to_grid(pointer);
        printf("(%d, %d)\n", grid.x, grid.y);

        if (isValidCoord(grid))
        {
            moveSelectedPiece(app, grid);
        }
        else
        {
            selected->img->x = selected->square->coord_x;
            selected->img->y = selected->square->coord_y;
        }

        app->state->selected = NULL;
    }
}

void mouseMotionInput(App app, SDL_Event e)
{
    Piece selected = app->state->selected;
    if (e.button.button == SDL_BUTTON_LEFT && selected != NULL)
    {
        selected->img->x = e.motion.x;
        selected->img->y = e.motion.y;
    }
}