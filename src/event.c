#include <SDL2/SDL.h>
#include "main.h"

#include "window.h"

SDL_Event events;

void processEvents(window_t *win) {
    while(SDL_PollEvent(&events) != 0) {
        switch(events.type) {
            case SDL_QUIT:
                win->isOpen = false;
                break;
        }
    }
}
