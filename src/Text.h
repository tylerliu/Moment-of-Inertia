//
// Created by Tyler on 2017/07/31.
//

#ifndef TEXT_H
#define TEXT_H

#include <stdbool.h>


void write_instr(uint32_t instr);
void start_text();
int decode_text_line(char *buff);
void end_text();

#endif /* Text.h */
