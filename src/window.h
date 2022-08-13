#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct window_t {
    SDL_Window* SDLPtr;
    char name[256];
    bool isOpen;
} window_t;

window_t* createWindow(char*);
void destroyWindow(window_t*);

#endif
