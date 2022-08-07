#ifndef MAP_H
#define MAP_H

#include <stdint.h>

typedef struct map_t {
    uint16_t **mapFloor;
    uint16_t **mapObjects;
    uint32_t **mapHeroes;
    int sizeX;
    int sizeY;
} map_t;

struct map_t* createMap(int, int);
void destroyMap(struct map_t*);




#endif
