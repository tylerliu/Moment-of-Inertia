//
// Created by Tyler on 2017/08/02.
//

#ifndef HASH_H
#define HASH_H

#include <stdint.h>

#define HASH_NOT_FOUND 0xFFFFFFFF

void hash_init();

void hash_put(const char *name, uint32_t type, uint32_t value);

uint32_t hash_get(const char *name, uint32_t type);

void hash_delete();

#endif /* Hash.h */
