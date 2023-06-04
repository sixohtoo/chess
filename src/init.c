#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "constants.h"
#include "init.h"
#include "piece_list.h"
#include "utils.h"

void initPieces(App app, char *filename);
void initBoard(State state);

App initSDL()
{
    App app = malloc(sizeof(struct app));
    // app->window = NULL;
    // app->renderer = NULL;

    int renderer_flags, window_flags;
    renderer_flags = SDL_RENDERER_ACCELERATED;

    window_flags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_Init went wrong... %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        printf("IMG_Init went wrong... %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    app->window = SDL_CreateWindow(
        "Chess",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        window_flags);

    if (!app->window)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_HEIGHT, SCREEN_WIDTH, SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);

    if (!app->renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return app;
}

void initApp(App app, char *filename)
{
    app->state = initState(app, filename);
    // return app;
}

void cleanup()
{
    SDL_Quit();
    IMG_Quit();
}

State initState(App app, char *saveName)
{
    State state = malloc(sizeof(struct state));
    app->state = state;
    initBoard(state);
    state->selected = NULL;
    state->turn = 1;
    state->playerTurn = WHITE;
    state->pieces = initPieceList();
    initPieces(app, saveName);
    return state;
}

void initBoard(State state)
{
    Board board = malloc(sizeof(void *) * 8);
    state->board = board;

    for (int row = 0; row < NUM_SQUARES_ROW; row++)
    {
        state->board[row] = malloc(sizeof(Square) * 8);
        for (int col = 0; col < NUM_SQUARES_ROW; col++)
        {
            state->board[row][col] = createSquare(row, col);
        }
    }
}

void initPieces(App app, char *saveName)
{
    char path[MAX_FILE_NAME] = "./saves/";
    FILE *file = fopen(strcat(path, saveName), "r");
    if (file == NULL)
    {
        printf("Save game %s does not exist\n", strcat(path, saveName));
        exit(EXIT_FAILURE);
    }
    char contents[MAX_SAVE_LENGTH];
    fgets(contents, MAX_SAVE_LENGTH, file);
    printf("%s\n", contents);

    // SDL_Surface *surface = IMG_Load("imgs/pieces_sprite.png");
    // SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    // SDL_FreeSurface(surface);

    SDL_Texture *img = IMG_LoadTexture(app->renderer, SPRITE);
    if (img == NULL)
    {
        printf("Image: %s couldn't be loaded: %s\n", SPRITE, SDL_GetError());
    }

    for (int i = 0; i < TOTAL_SQUARES; i++)
    {
        printf("%d\n", i);
        if (contents[i] != '.')
        {
            struct coord c = square_num_to_coord(i);
            if (contents[i] == 'P')
            {
                printf("black\n");
            }
            // printf("%c\n", contents[i]);
            // SDL_SetRenderDrawColor(app->renderer, 105, 250, 250, 210);
            // SDL_Rect rect = {
            //     CHESS_BOARD_BORDER + c.x * CHESS_SQUARE_SIZE + CHESS_SQUARE_SIZE / 2,
            //     CHESS_BOARD_BORDER + c.y * CHESS_SQUARE_SIZE + CHESS_SQUARE_SIZE / 2,
            //     PIECE_SIZE,
            //     PIECE_SIZE};
            SDL_Rect *rect = malloc(sizeof(SDL_Rect)); // where piece will be
            rect->x = CHESS_BOARD_BORDER + c.x * CHESS_SQUARE_SIZE + PIECE_OFFSET;
            rect->y = CHESS_BOARD_BORDER + c.y * CHESS_SQUARE_SIZE + PIECE_OFFSET;
            rect->w = PIECE_SIZE;
            rect->h = PIECE_SIZE;

            // char *img_file = "imgs/pawn."
            // SDL_rect rect = malloc(sizeof(struct))
            Square square = app->state->board[c.x][c.y];
            Piece piece = createPiece(c.x, c.y, contents[i], rect, img, square); // will rect be freed?
            // SDL_RenderFillRect(app->renderer, rect);
            addPiece(app->state->pieces, piece);
        }
    }

    printf("head is %p\n", app->state->pieces->head);

    // Create pawns
    // Create rooks
    // Create knights
    // Create bishops
    // Create queen
    // Create king
}

// void loadImg()
// {
// }