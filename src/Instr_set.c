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
    instr->imm0_11 = (uint32_t)(imm & 0XFFF);
}

void fill_imm_S(Instr_format_S *instr, int32_t imm){
    instr->imm0_4 = (uint32_t)(imm & 0X1F);
    instr->imm5_11 = (uint32_t)((imm >> 5) & 0X7F);
}

void fill_imm_SB(Instr_format_SB *instr, int32_t imm){
    imm >>= 1;
    instr->imm1_4 = (uint32_t)(imm & 0xF);
    imm >>= 4;
    instr->imm5_10 = (uint32_t)(imm & 0x7F);
    imm >>= 7;
    instr->imm11 = (uint32_t)(imm & 1);
    instr->imm11 = (uint32_t)((imm >> 1) & 1);
}

void fill_imm_U(Instr_format_U *instr, int32_t imm){
    instr->imm12_31 = (uint32_t)imm >> 12;
}

void fill_imm_UJ(Instr_format_UJ *instr, int32_t imm){
    imm >>= 1;
    instr->imm1_10 = (uint32_t)(imm & 0x1FF);
    imm >>= 9;
    instr->imm11 = (uint32_t)(imm & 1);
    imm >>= 1;
    instr->imm12_19 = (uint32_t)(imm & 0xFF);
    imm >>= 8;
    instr->imm20 = (uint32_t)(imm & 1);

}

void parse_R(Instr_format_R *instr, char *param){
    uint8_t rd, rs1, rs2;
    sscanf(param, "%hhu,%hhu,%hhu", &rd, &rs1, &rs2);
    instr->rd = rd;
    instr->rs1 = rs1;
    instr->rs2 = rs2;
}

void parse_R4(Instr_format_R4 *instr, char *param){
    uint8_t rd, rs1, rs2, rs3;
    sscanf(param, "%hhu,%hhu,%hhu,%hhu", &rd, &rs1, &rs2, &rs3);
    instr->rd = rd;
    instr->rs1 = rs1;
    instr->rs2 = rs2;
    instr->rs3 = rs3;
}

void parse_R4OP(Instr_format_R4 *instr, char *param){
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

void parse_SB(Instr_format_SB *instr, char *param){
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu,%hhu,%d", &rs1, &rs2, &imm);
    instr->rs1 = rs1;
    instr->rs2 = rs2;
    fill_imm_SB(instr, imm);
}

void parse_U(Instr_format_U *instr, char *param){
    uint8_t rd;
    int32_t imm;
    sscanf(param, "%hhu,%d", &rd, &imm);
    instr->rd = rd;
    fill_imm_U(instr, imm);
}

void parse_UJ(Instr_format_UJ *instr, char *param){
    uint8_t rd;
    int32_t imm;
    sscanf(param, "%hhu,%d", &rd, &imm);
    instr->rd = rd;
    fill_imm_UJ(instr, imm);
}