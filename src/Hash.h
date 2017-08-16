//
// Created by Tyler on 2017/08/02.
//

#ifndef HASH_H
#define HASH_H

#include <stdint.h>

#define HASH_NOT_FOUND 0xFFFFFFFF
#define HASH_TYPE_TEXT 0
#define HASH_TYPE_DATA 1
#define HASH_TYPE_SPACE 2

uint32_t last_type; //type of last get element

void hash_init();

void hash_put(const char *name, uint32_t type, uint32_t value);

uint32_t hash_get(const char *name);

void hash_delete();

#endif /* Hash.h */
