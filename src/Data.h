//
// Created by Tyler on 2017/08/01.
//

#ifndef DATA_H
#define DATA_H

#include <stdint.h>

/*
 * Data type:
 * .ascii ascii string
 * .asciiz ascii string with \0 at the end
 * .byte 1 byte words
 * .halfword 2 byte words
 * .word 4byte words
 * .float floats
 * .double doubles
 * .space 0-filled spaces
 */

 //identifier must not start with digit, must end with :


#define ASCIIZ 8
#define ASCII 9
#define BYTE 10
#define HALF 11
#define WORD 12
#define FLOAT 13
#define DOUBLE 14
#define SPACE 15

#define GLOBAL_NOT_FOUND -100000

void start_data();
void decode_data_line(char *line);
void end_data();
int32_t data_get(char *name);
void write_global();
void force_exit();

#endif /* Data.h */
