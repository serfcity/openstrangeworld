#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include "map.h"
#include "list.h"
#include "main.h"

map_t* createMap(int x, int y) {
    map_t* newMap = malloc(sizeof(map_t));
    newMap->mapFloor = malloc(sizeof(uint16_t*) * x);
    
    if(newMap->mapFloor == NULL)
        return NULL;
    
    newMap->sizeX = x;
    newMap->sizeY = y;
    
    for(int i = 0; i < x; i++) {
        newMap->mapFloor[i] = malloc(sizeof(uint16_t) * y);
        if(newMap->mapFloor[i] == NULL)
            return NULL;
    }
    
    newMap->mapObjects = malloc(sizeof(uint16_t*) * x);
    
    if(newMap->mapObjects == NULL)
        return NULL;
    
    for(int i = 0; i < x; i++) {
        newMap->mapObjects[i] = malloc(sizeof(uint16_t) * y);
        if(newMap->mapObjects[i] == NULL)
            return NULL;
    }
    
    newMap->mapHeroes = malloc(sizeof(list_int32_t**) * x * y);
    
    if(newMap->mapHeroes == NULL)
        return NULL;
    
    for(int i = 0; i < x; i++) {
        newMap->mapHeroes[i] = malloc(sizeof(list_int32_t*) * y);
        if(newMap->mapHeroes[i] == NULL)
            return NULL;
    }
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            newMap->mapHeroes[i][j] = createList();
            if(newMap->mapHeroes[i][j] == NULL)
                return NULL;
        }
    }
    
    return newMap;
}

void destroyMap(struct map_t* m) {
    for(int i = 0; i < m->sizeX; i++) {
        free(m->mapFloor[i]);
    }
    free(m->mapFloor);
    
    for(int i = 0; i < m->sizeX; i++) {
        free(m->mapObjects[i]);
    }
    free(m->mapObjects);
    
    for(int i = 0; i < m->sizeX; i++) {
        free(m->mapHeroes[i]);
    }
    free(m->mapHeroes);
    free(m);
}
