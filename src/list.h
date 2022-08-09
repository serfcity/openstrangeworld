#ifndef LIST_H
#define LIST_H

#include <stdint.h>



typedef struct list_int32_t {
    int32_t value;
    struct list_int32_t* previous;
    struct list_int32_t* next;
} list_int32_t;

list_int32_t* createList();
void destroyList(list_int32_t*);
int pushBackList(list_int32_t*, int32_t);
void deleteElementList(list_int32_t*, int);
int32_t atList(list_int32_t*, int);

#endif
