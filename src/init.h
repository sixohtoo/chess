
#ifndef GAMES_INIT
#define GAMES_INIT

#include "types.h"

// Initalises SDL and creates renderer and window
void initSDL(App app);

// Initialises the app struct
App initApp(char *saveName);

// Cleans up code
void cleanup();

// Initialises state
State initState(App app, char *saveName);

#endif