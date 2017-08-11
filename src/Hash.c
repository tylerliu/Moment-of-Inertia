//
// Created by Tyler on 2017/08/02.
//

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Hash.h"

#define TABLE_LENGTH 513
#define NOT_ALLOW_REPEAT

typedef struct{
    char name[64];
    uint32_t type;
    uint32_t value;
    uint32_t next;
} map_element;

uint32_t arr_len = 64;
uint32_t used = 1;
map_element *elements; //nothing should be stored at 0

uint32_t table[TABLE_LENGTH]; //points to 0 if nothing

void hash_init(){
    elements = (map_element *) malloc(arr_len * sizeof(map_element));
}

uint32_t ELFHash(const char *key){
    unsigned long h = 0, g = 0;
    while(*key){
        h = (h << 4) + *key++;
        g = h & 0XF0000000L;
        if (g) h ^= g >> 24;
        h &= ~g;
    }
    return (uint32_t)h % TABLE_LENGTH;
}

void hash_put(const char *name, uint32_t type, uint32_t value){
    if (arr_len == used){
        arr_len <<= 1;
        elements = (map_element *) realloc(elements, arr_len * sizeof(map_element));
    }
    used ++;

    strcpy(elements[used - 1].name, name);
    elements[used - 1].type = type;
    elements[used - 1].value = value;
    elements[used - 1].next = 0;

    //place in table
    uint32_t loc = ELFHash(name);
    if (table[loc] == 0) table[loc] = used - 1;
    else {
        loc = table[loc];
        while (elements[loc].next != 0) {
#ifdef NOT_ALLOW_REPEAT
            if (!strcmp(elements[loc].name, name) && elements[loc].type == type){
                fprintf(stderr, "REPEATED IDENTIFIER: %s\n", name);
                return;
            }
#endif
            loc = elements[loc].next;
        }
#ifdef NOT_ALLOW_REPEAT
        if (!strcmp(elements[loc].name, name) && elements[loc].type == type){
            fprintf(stderr, "REPEATED IDENTIFIER: %s\n", name);
            return;
        }
#endif
        elements[loc].next = used - 1;
    }
}

uint32_t hash_get(const char *name, uint32_t type){
    uint32_t loc = table[ELFHash(name)];
    while (loc != 0){
        if (!strcmp(elements[loc].name, name) && elements[loc].type == type){ //correct
            return elements[loc].value;
        }
        loc = elements[loc].next;
    }
    return HASH_NOT_FOUND; //not found
}

void hash_delete(){
    free(elements);
}
