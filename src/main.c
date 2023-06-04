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
    char *saveName = "pawn";
    App app = initApp(saveName);
    initSDL(app);

    printf("Starting chess!\n");

    atexit(cleanup);

    while (1)
    {
        prepareScene(app);
        doInput(app);
        presentScene(app);
        SDL_Delay(TICK_DELAY);
    }

    return EXIT_SUCCESS;
}