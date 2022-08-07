#include <SDL2/SDL.h>
#include "main.h"

SDL_Event events;

void processEvents() {
    while(SDL_PollEvent(&events) != 0) {
        switch(events.type) {
            case SDL_QUIT:
                windowIsOpen = false;
                break;
        }
    }
}
