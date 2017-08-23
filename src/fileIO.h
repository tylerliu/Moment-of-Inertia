//
// Created by Tyler on 2017/07/31.
//

#ifndef FILEIO_H
#define FILEIO_H

#include <stdint.h>
#include <stdio.h>

FILE *in;
FILE *out;

void write_int32(uint32_t int32);
void write_segment(uint32_t len, void * segment);

char * readline();
int parse_data();
int parse_text();

int startwith(char *source, const char *pattern);
int startwith_incensitive(char *source, const char *pattern);
char *skip_space(char *str);

#endif /* FileIO.h */
