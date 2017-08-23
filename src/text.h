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
void write_text();
void text_force_exit();

//for label.h
uint32_t get_instr(uint32_t loc);
void set_instr(uint32_t loc, uint32_t instr);
uint32_t get_text_loc();

#endif /* Text.h */
