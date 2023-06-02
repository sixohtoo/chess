#include <SDL2/SDL.h>
#include "types.h"
#include "constants.h"
#include "init.h"

void initSDL(App app)
{
    int renderer_flags, window_flags;
    renderer_flags = SDL_RENDERER_ACCELERATED;

    window_flags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_Init went wrong... %s", SDL_GetError());
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
}

App initApp()
{
    App app = malloc(sizeof(struct app));
    app->window = NULL;
    app->renderer = NULL;
    return app;
}

void cleanup()
{
    SDL_Quit();
}
