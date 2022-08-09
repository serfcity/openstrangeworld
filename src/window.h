#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <uchar.h>

typedef struct window_t {
    SDL_Window* SDLPtr;
    char32_t name[256];
} window_t;

window_t* createWindow(char32_t*);
void destroyWindow(window_t*);

#endif
