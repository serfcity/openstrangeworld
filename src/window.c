#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "window.h"

window_t* createWindow(char *name) {
    window_t* win = malloc(sizeof(window_t));
    if(win == NULL) {
        return NULL;
    }
    strcpy(win->name, name);
    
    win->SDLPtr = SDL_CreateWindow(
            name,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            600,
            SDL_WINDOW_OPENGL
            );
    if(win->SDLPtr == NULL) {
        return NULL;
    }
    win->isOpen = true;
    return win;
}

void destroyWindow(window_t *win) {
    SDL_DestroyWindow(win->SDLPtr);
    free(win);
}
