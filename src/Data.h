//
// Created by Tyler on 2017/08/01.
//

#ifndef DATA_H
#define DATA_H

/*
 * Data type:
 * .ascii ascii string
 * .asciiz ascii string with \0 at the end
 * .byte 1 byte words
 * .halfword 2 byte words
 * .word 4byte words
 * .float floats
 * .double doubles
 * .space spaces
 */


void start_data();
void decode_data_line(char *line);

#endif /* Data.h */
