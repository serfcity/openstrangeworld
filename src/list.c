#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include "list.h"
#include "main.h"

list_int32_t* createList() {
    list_int32_t* newList = malloc(sizeof(list_int32_t));
    if(newList == NULL) {
        perror("Malloc error in list");
        return NULL;
    }
    newList->value = 0;
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
    list_int32_t *pre, *nxt, *this;
    
    #ifdef WARNING
    if(id == 0) {
        perror("Warning: delete 0 element from list. You may use broken pointer yet.");
    }
    #endif
    
    do {
        pre = lst->previous;
        nxt = lst->next;
        this = lst;
        if(it == id) {
            lst = nxt;
                lst->previous = pre;
            if(pre != NULL) {
                lst = pre;
                lst->next = nxt;
            }
            lst = this;
            free(lst);
            return;
      } 
        it++;
        lst = lst->next;
    } while(lst->next != NULL);
    perror("Out of list");
    exit(1);
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
    if(it == id) {
        return lst->value;
    }
    perror("Out of list");
    exit(1);
}


void destroyList(list_int32_t* lst) {
    while(lst->next != NULL) {
        lst = lst->next;
        if(lst->previous != NULL) {
            free(lst->previous);
        }
    }
    free(lst);
}

