#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "map.h"
#include "event.h"
#include "window.h"

bool windowIsOpen = false;

int main(int argc, char **argv) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        perror("SDL init error: ");
        perror(SDL_GetError());
        exit(1);
    }
    
    window_t *window = createWindow("openstrangeworld");

    if(window == NULL) {
        perror("SDL create window error");
        exit(1);
    }
    
    
    while(window->isOpen) {
        processEvents(window);
    }
    
    destroyWindow(window);

    SDL_Quit();
}
