#include <stdio.h>
#include <SDL2/SDL.h>
#define SDL_MAIN_HANDLED
#include "constants.h"
#include "init.h"
#include "types.h"
#include "draw.h"
#include "input.h"

int main()
{
    App app = initApp();
    initSDL(app);

    State state = initState();

    printf("Starting chess!\n");

    atexit(cleanup);

    while (1)
    {
        prepareScene(app);
        doInput();
        presentScene(app);
        SDL_Delay(50);
    }

    return EXIT_SUCCESS;
}