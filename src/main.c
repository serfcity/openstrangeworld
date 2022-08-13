#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "map.h"
#include "event.h"
#include "list.h"
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
        perror("SDL create window error: ");
        perror(SDL_GetError());
        exit(1);
    }
    
    
    list_int32_t* l = createList();
    pushBackList(l, 0);
    pushBackList(l, 1);
    pushBackList(l, 2);
    pushBackList(l, 3);
    deleteElementList(l, 1);
    
    
    printf("%d %d %d %d", atList(l, 0), atList(l, 1), atList(l, 2), atList(l, 3));
    
    
    
    while(window->isOpen) {
        processEvents(window);
    }
    
    destroyWindow(window);

    SDL_Quit();
}
