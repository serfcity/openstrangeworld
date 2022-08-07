#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "map.h"

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
    
    
    SDL_Delay(1000);
    
    
    SDL_Quit();
}
