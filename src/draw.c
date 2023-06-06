#include <SDL2/SDL.h>
#include "types.h"
#include "constants.h"
#include <stdio.h>

void drawChessBoard(App app);
void placePieces(App app);

void prepareScene(App app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    // SDL_Render
    SDL_RenderClear(app->renderer);
    drawChessBoard(app);
    // placePieces(app);
    // printf("Rendered board\n");
}

void drawChessBoard(App app)
{
    SDL_SetRenderDrawColor(app->renderer, 105, 105, 105, 255);
    SDL_Rect rect = {
        CHESS_BOARD_BORDER,
        CHESS_BOARD_BORDER,
        CHESS_BOARD_HEIGHT,
        CHESS_BOARD_WIDTH};
    // SDL_RenderCl
    SDL_RenderFillRect(app->renderer, &rect);

    // Draws light coloured squares
    SDL_SetRenderDrawColor(app->renderer, 220, 200, 200, 255);
    for (int row = 0; row < 4; row += 1)
    {
        for (int col = 0; col < 4; col += 1)
        {
            SDL_RenderFillRect(app->renderer, app->state->board[row * 2][col * 2]->rect);
            SDL_RenderFillRect(app->renderer, app->state->board[row * 2 + 1][col * 2 + 1]->rect);
        }
    }

    // Draw legal moves
    SDL_SetRenderDrawBlendMode(app->renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(app->renderer, 250, 128, 114, 200);
    SquareNode curr = app->state->displayedSquares;
    while (curr != NULL)
    {
        SDL_RenderFillRect(app->renderer, curr->square->rect);
        curr = curr->next;
    }

    placePieces(app);
}

void placePieces(App app)
{
    PieceNode curr = app->state->pieces;
    while (curr != NULL)
    {
        SDL_RenderCopy(app->renderer, curr->piece->img, curr->piece->img_src, curr->piece->img_dest);
        // SDL_SetRenderDrawColor(app->renderer, 105, 250, 250, 210);
        // SDL_RenderFillRect(app->renderer, curr->piece->img);
        curr = curr->next;
    }
}

void presentScene(App app)
{
    SDL_RenderPresent(app->renderer);
}

// SDL_Rect getSprite(enum PieceType piece, enum Colour colour)
// {

// }