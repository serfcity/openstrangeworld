#include <stdio.h>
#include <uchar.h>
#include <memory.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "window.h"

window_t* createWindow(char32_t *name) {
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
}
