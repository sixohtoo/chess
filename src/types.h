#include <SDL2/SDL.h>

#ifndef GAME_TYPES
#define GAME_TYPES

typedef struct app
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} *App;

#endif