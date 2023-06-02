#include <SDL2/SDL.h>

void doInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
        }
    }
}