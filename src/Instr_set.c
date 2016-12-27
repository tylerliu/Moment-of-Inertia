//
//  Instr_set.c
//  Inertia
//
//  Created by Tyler Liu on 2016/12/03.
//  Copyright © 2016 Tyler Liu. All rights reserved.

#include <stdio.h>
#include "Instr_set.h"
//parse instructions


//fill in immediate value
void fill_imm_I(Instr_format_I *instr, int32_t imm){
    instr->imm = (uint32_t)(imm & 0X3FFF);
}

void fill_imm_S(Instr_format_S *instr, int32_t imm){
    instr->imm = (uint32_t)(imm & 0X3FFF);
}

void fill_imm_U(Instr_format_U *instr, int32_t imm){
    instr->imm = (uint32_t)imm >> 13;
}

void fill_imm_UJ(Instr_format_U *instr, int32_t imm){
    instr->imm = (uint32_t)(imm & 0X7FFFF);
}

void parse_R(Instr_format_R *instr, char *param){
    uint8_t rd, rs1, rs2;
    sscanf(param, "%hhu,%hhu,%hhu", &rd, &rs1, &rs2);
    instr->rd = rd;
    instr->rs1 = rs1;
    instr->rs2 = rs2;
}

void parse_I(Instr_format_I *instr, char *param){
    uint8_t rd, rs1;
    int32_t imm;
    sscanf(param, "%hhu,%hhu,%d", &rd, &rs1, &imm);
    instr->rd = rd;
    instr->rs1 = rs1;
    fill_imm_I(instr, imm);
}

void parse_S(Instr_format_S *instr, char *param){
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu,%hhu,%d", &rs1, &rs2, &imm);
    instr->rs1 = rs1;
    instr->rs2 = rs2;
    fill_imm_S(instr, imm);
}


void parse_U(Instr_format_U *instr, char *param){
    uint8_t rd;
    int32_t imm;
    sscanf(param, "%hhu,%d", &rd, &imm);
    instr->rd = rd;
    fill_imm_U(instr, imm);
}

void parse_UJ(Instr_format_U *instr, char *param){
    uint8_t rd;
    int32_t imm;
    sscanf(param, "%hhu,%d", &rd, &imm);
    instr->rd = rd;
    fill_imm_UJ(instr, imm);
}