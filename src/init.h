
#ifndef GAMES_INIT
#define GAMES_INIT

#include "types.h"

// Initalises SDL and creates renderer and window
App initSDL();

// Initialises the app struct
void initApp(App app, char *saveName);

// Cleans up code
void cleanup();

// Initialises state
State initState(App app, char *saveName);

#endif