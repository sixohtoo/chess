#include "types.h"

#ifndef GAMES_INIT
#define GAMES_INIT

// Initalises SDL and creates renderer and window
void initSDL(App app);

// Initialises the app struct
App initApp();

// Cleans up code
void cleanup();

#endif