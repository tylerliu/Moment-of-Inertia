//
// Created by Tyler on 2017/07/31.
//

#ifndef FILEIO_H
#define FILEIO_H

#include <stdint.h>
#include <stdio.h>

#define READ_SUCCESS 1

FILE *in;
FILE *out;

uint32_t bytes_written;

void write_int32(uint32_t int32);
char * readline();
int categorize_parse();

#endif /* FileIO.h */
