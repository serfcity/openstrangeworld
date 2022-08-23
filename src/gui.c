#include <stdio.h>
#include <SDL2/SDL.h>
#include "main.h"

const int blockSizeX = 25;      //Block size in pixels
const int blockSizeY = 25;      //Block size in pixels
const int blocksInScreenX = 32; //How many blocks included in screen
const int blocksInScreenY = 24; //How many blocks included in screen

int mapX;                       //Map size
int mapY;                       //Map size

int cameraPonterX;              //Top-left block of camera
int cameraPonterY;              //Top-left block of camera

/**
 * Set map size in blocks
 */
void mapSet(int sizeX, int sizeY) {
    mapX = sizeX;
    mapY = sizeY;
}


/**
 * Set camera position by top-level block
 */
void setCamera(int posX, int posY) {
    if(posX > mapX - blocksInScreenX ||
    posY > mapY - blocksInScreenY) {
        #ifdef WARNING
            perror("Warning: camera out of map ignored");
        #endif
    }
    else {
        cameraPonterX = posX;
        cameraPonterY = posY;
    }
}
