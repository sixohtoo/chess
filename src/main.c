#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        printf("SDL_Init went wrong... %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    printf("HELLO %s\n", "mate");
    printf("ok do this now\n");

    SDL_Quit();

    return EXIT_SUCCESS;
}