#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include "list.h"

list_int32_t* createList() {
    list_int32_t* newList = malloc(sizeof(list_int32_t));
    if(newList == NULL) {
        perror("Malloc error in list");
        return NULL;
    }
    newList->previous = NULL;
    newList->next = NULL;
    return newList;
}

int pushBackList(list_int32_t* lst, int32_t value) {
    while(lst->next != NULL) {
        lst = lst->next;
    }
    list_int32_t* next = malloc(sizeof(list_int32_t));
    if(next == NULL) {
        perror("Malloc error in list");
        return 1;
    }
    next->value = value;
    next->next = NULL;
    next->previous = lst;
    lst->next = next;
    return 0;
}

void deleteElementList(list_int32_t* lst, int id) {
    int it = 0;
    while(lst->next != NULL) {
        if(it == id) {
            list_int32_t* nowNext = lst->next;
            list_int32_t* nowPrevious = lst->previous;
            lst = lst->previous;
            list_int32_t* nowThis = lst->next;
            lst->next = nowNext;
            lst = nowNext;
            lst->previous = nowPrevious;
            free(nowThis);
        }
        lst = lst->next;
        it++;
    }
}

int atList(list_int32_t* lst, int id) {
    int it = 0;
    do {
        if(it == id) {
            return lst->value;
        }
        lst = lst->next;
        it++;
    } while(lst->next != NULL);
    perror("Out of list");
    exit(1);
}

void destroyList(list_int32_t* lst) {
    free(lst);
    while(lst->next != NULL) {
        lst = lst->next;
        free(lst);
    }
}

