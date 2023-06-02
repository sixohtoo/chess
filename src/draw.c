#include <SDL2/SDL.h>
#include "types.h"
#include "constants.h"
#include <stdio.h>

void drawChessBoard(App app);

void prepareScene(App app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
    drawChessBoard(app);
    printf("Rendered board\n");
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

    SDL_SetRenderDrawColor(app->renderer, 220, 200, 200, 255);
    for (int row = 0; row < 4; row += 1)
    {
        for (int col = 0; col < 4; col += 1)
        {
            SDL_Rect square1 = {
                row * 2 * CHESS_SQUARE_SIZE + CHESS_BOARD_BORDER,
                col * 2 * CHESS_SQUARE_SIZE + CHESS_BOARD_BORDER,
                CHESS_SQUARE_SIZE,
                CHESS_SQUARE_SIZE};
            SDL_RenderFillRect(app->renderer, &square1);
            SDL_Rect square2 = {
                row * 2 * CHESS_SQUARE_SIZE + CHESS_BOARD_BORDER + CHESS_SQUARE_SIZE,
                col * 2 * CHESS_SQUARE_SIZE + CHESS_BOARD_BORDER + CHESS_SQUARE_SIZE,
                CHESS_SQUARE_SIZE,
                CHESS_SQUARE_SIZE};
            SDL_RenderFillRect(app->renderer, &square2);
        }
    }
}

void presentScene(App app)
{
    SDL_RenderPresent(app->renderer);
}