#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "map.h"
#include "event.h"
#include "list.h"

bool windowIsOpen = false;

int main(int argc, char **argv) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        perror("SDL init error: ");
        perror(SDL_GetError());
        exit(1);
    }
    
    SDL_Window *window = SDL_CreateWindow("tdemo",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800,
                                          600,
                                          SDL_WINDOW_OPENGL
                                         );
    
    if(window == NULL) {
        perror("SDL create window error: ");
        perror(SDL_GetError());
        exit(1);
    }
    
    windowIsOpen = true;
    
    list_int32_t* list = createList();
    if(list == NULL) exit(1);
    
    pushBackList(list, 1);
    pushBackList(list, 2);
    pushBackList(list, 3);
    pushBackList(list, 4);
    deleteElementList(list, 2);
    
    printf("%d %d %d %d",
           atList(list, 0),
           atList(list, 1),
           atList(list, 2),
           atList(list, 3)
          );
    
    while(windowIsOpen) {
        processEvents();
    }
    
    
    SDL_Quit();
}
