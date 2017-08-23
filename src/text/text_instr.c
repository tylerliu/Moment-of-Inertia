//
//  Execution.c
//  Inertia
//
//  Created by Tyler Liu on 2016/12/03.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//
//  execution function

#include "text_instr.h"
#include "Instr_set.h"
#include "../Data.h"
#include "../error.h"
#include "label.h"
#include "../fileIO.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NEW_INSTR(format) Instr_format_##format instr;\
                            *(uint32_t *)&instr = 0\

//parse of IO functions
uint32_t parseIO(char *param);

// Integer Register-Immediate Instructions, type I

uint32_t addi(char *param){
    NEW_INSTR(I);
    instr.opcode = ADDI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slti(char *param){
    NEW_INSTR(I);
    instr.opcode = SLTI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltui(char *param){
    NEW_INSTR(I);
    instr.opcode = SLTUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t andi(char *param){
    NEW_INSTR(I);
    instr.opcode = ANDI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t ori(char *param){
    NEW_INSTR(I);
    instr.opcode = ORI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xori(char *param){
    NEW_INSTR(I);
    instr.opcode = XORI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slli(char *param){
    NEW_INSTR(I);
    instr.opcode = SLLI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srli(char *param){
    NEW_INSTR(I);
    instr.opcode = SRLI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srai(char *param){
    NEW_INSTR(I);
    instr.opcode = SRAI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t muli(char *param){
    NEW_INSTR(I);
    instr.opcode = MULI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divi(char *param){
    NEW_INSTR(I);
    instr.opcode = DIVI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divui(char *param){
    NEW_INSTR(I);
    instr.opcode = DIVUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remi(char *param){
    NEW_INSTR(I);
    instr.opcode = REMI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remui(char *param){
    NEW_INSTR(I);
    instr.opcode = REMUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//Integer Register-Register Operations, type R
//OP
uint32_t add(char *param){
    NEW_INSTR(R);
    instr.opcode = ADD;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sub(char *param){
    NEW_INSTR(R);
    instr.opcode = SUB;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slt(char *param){
    NEW_INSTR(R);
    instr.opcode = SLT;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltu(char *param){
    NEW_INSTR(R);
    instr.opcode = SLTU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t and(char *param){
    NEW_INSTR(R);
    instr.opcode = AND;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t or(char *param){
    NEW_INSTR(R);
    instr.opcode = OR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xor(char *param){
    NEW_INSTR(R);
    instr.opcode = XOR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sll(char *param){
    NEW_INSTR(R);
    instr.opcode = SLL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srl(char *param){
    NEW_INSTR(R);
    instr.opcode = SRL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sra(char *param){
    NEW_INSTR(R);
    instr.opcode = SRA;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t mul(char *param){
    NEW_INSTR(R);
    instr.opcode = MUL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t division(char *param){
    NEW_INSTR(R);
    instr.opcode = DIV;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divu(char *param){
    NEW_INSTR(R);
    instr.opcode = DIVU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t rem(char *param){
    NEW_INSTR(R);
    instr.opcode = REM;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remu(char *param){
    NEW_INSTR(R);
    instr.opcode = REMU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

//load upper immediate, type U, load imm to dest.
uint32_t lui(char *param){
    NEW_INSTR(U);
    instr.opcode = LUI;
    parse_U(&instr, param);
    return *(uint32_t *)&instr;
}

//add upper immediate to pc, type U, load imm + pc to dest.
uint32_t auipc(char *param){
    NEW_INSTR(U);
    instr.opcode = AUIPC;
    parse_U(&instr, param);
    return *(uint32_t *)&instr;
}

//Unconditional jumps, type U, add immediate to pc.if dest = 0, plain jump. store pc+4 to dest after jump.
uint32_t jal(char *param){
    NEW_INSTR(U);
    instr.opcode = JAL;
    parse_UJ(&instr, param);
    return *(uint32_t *)&instr;
}

//jump and link register, type I, store pc+4 to dest after jump.
uint32_t jalr(char *param){
    NEW_INSTR(I);
    instr.opcode = JALR;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

static inline void check_symbol(char *param){
    char *place = strrchr(param, ',') + 1;
    place = strrchr(param, ' ') + 1 > place ? strrchr(param, ' ') + 1 : place;
    place = strrchr(param, '\t') + 1 > place ? strrchr(param, '\t') + 1 : place;
    if (!isdigit(*place) && *place != '+' && *place != '-' ){
        uint32_t loc = ref_label(place);
        if (loc == LABEL_FILL_TEMP) loc = 1;
        sprintf(place, "%d", loc);
    }
}

//branch statements, type S, shift of offest.
//BRANCH
uint32_t beq(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BEQ;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bne(char *param){
    check_symbol(param);
    NEW_INSTR(S);   
    instr.opcode = BNE;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t blt(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLT;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bltu(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLTU;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bge(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGE;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bgeu(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGEU;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//load from int_memory, type I, The effective byte = s1 + IMM.
uint32_t lw(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //lw ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return lw(name);
    }
    NEW_INSTR(I);
    instr.opcode = LW;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lh(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //lh ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return lh(name);
    }
    NEW_INSTR(I);
    instr.opcode = LH;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lhu(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //lhu ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return lhu(name);
    }
    NEW_INSTR(I);
    instr.opcode = LHU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lb(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //lb ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return lb(name);
    }
    NEW_INSTR(I);
    instr.opcode = LB;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lbu(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //lbu ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return lbu(name);
    }
    NEW_INSTR(I);
    instr.opcode = LBU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t sw(char *param){
    if (strchr(param, '@') != NULL){
        //store global
        //sw ?, @global
        char name[64];
        uint8_t source;
        sscanf(param, "%hhu%*[ \n,]@%s", &source, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "4,%hhu,%d", source, offset);
        return sw(name);
    }
    NEW_INSTR(S);
    instr.opcode = SW;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sh(char *param){
    if (strchr(param, '@') != NULL){
        //store global
        //sh ?, @global
        char name[64];
        uint8_t source;
        sscanf(param, "%hhu%*[ \n,]@%s", &source, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "4,%hhu,%d", source, offset);
        return sh(name);
    }
    NEW_INSTR(S);
    instr.opcode = SH;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sb(char *param){
    if (strchr(param, '@') != NULL){
        //store global
        //sb ?, @global
        char name[64];
        uint8_t source;
        sscanf(param, "%hhu%*[ \n,]@%s", &source, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "4,%hhu,%d", source, offset);
        return sb(name);
    }
    NEW_INSTR(S);
    instr.opcode = SB;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//RV32F/RV32D

//load from memory, type I, The effective byte = s1 + IMM.
uint32_t flw(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //flw ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return flw(name);
    }
    NEW_INSTR(I);
    instr.opcode = FLW;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fld(char *param){
    if (strchr(param, '@') != NULL){
        //load global
        //fld ?, @global
        char name[64];
        uint8_t dest;
        sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "%hhu,4,%d", dest, offset);
        return fld(name);
    }
    NEW_INSTR(I);
    instr.opcode = FLD;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t fsw(char *param){
    if (strchr(param, '@') != NULL){
        //store global
        //fsw ?, @global
        char name[64];
        uint8_t source;
        sscanf(param, "%hhu%*[ \n,]@%s", &source, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "4,%hhu,%d", source, offset);
        return fsw(name);
    }
    NEW_INSTR(S);
    instr.opcode = FSW;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsd(char *param){
    if (strchr(param, '@') != NULL){
        //store global
        //fsd ?, @global
        char name[64];
        uint8_t source;
        sscanf(param, "%hhu%*[ \n,]@%s", &source, name);
        int32_t offset = data_get(name);
        if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
        sprintf(name, "4,%hhu,%d", source, offset);
        return fsd(name);
    }
    NEW_INSTR(S);
    instr.opcode = FSD;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//FP_OP
uint32_t fadd(char *param){
    NEW_INSTR(R);
    instr.opcode = FADD;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsub(char *param){
    NEW_INSTR(R);
    instr.opcode = FSUB;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fmul(char *param){
    NEW_INSTR(R);
    instr.opcode = FMUL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fdiv(char *param){
    NEW_INSTR(R);
    instr.opcode = FDIV;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsqrt(char *param){
    NEW_INSTR(R);
    instr.opcode = FSQRT;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_w(char *param){
    NEW_INSTR(R);
    instr.opcode = FCVT_D_W;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_wu(char *param){
    NEW_INSTR(R);
    instr.opcode = FCVT_D_WU;
    strcat(param, ",1");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_w_d(char *param){
    NEW_INSTR(R);
    instr.opcode = FCVT_W_D;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_wu_d(char *param){
    NEW_INSTR(R);
    instr.opcode = FCVT_WU_D;
    strcat(param, ",1");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t f_eq(char *param){
    NEW_INSTR(R);
    parse_R(&instr, param);
    instr.opcode = F_EQ;
    return *(uint32_t *)&instr;
}

uint32_t f_lt(char *param){
    NEW_INSTR(R);
    parse_R(&instr, param);
    instr.opcode = F_LT;
    return *(uint32_t *)&instr;
}

uint32_t f_le(char *param){
    NEW_INSTR(R);
    parse_R(&instr, param);
    instr.opcode = F_LE;
    return *(uint32_t *)&instr;
}

uint32_t fmv(char *param){
    NEW_INSTR(R);
    instr.opcode = FMV;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fneg(char *param){
    NEW_INSTR(R);
    instr.opcode = FNEG;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t Fabs(char *param){
    NEW_INSTR(R);
    instr.opcode = FABS;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

//Pseudo-instructions
extern void write_instr(uint32_t instr);

uint32_t nop(char *param){
    NEW_INSTR(I);
    instr.opcode = ADDI;
    return *(uint32_t *)&instr;
}

uint32_t li(char *param){
    uint8_t rd;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rd, &imm);
    if (imm >> 13 == 0 || imm >> 13 == -1){
        //1 instruction
        Instr_format_I instr;
        *(uint32_t *)&instr = 0;
        instr.opcode = ADDI;
        instr.rd = rd;
        instr.rs1 = 0;
        fill_imm_I(&instr, imm);
        return *(uint32_t *)&instr;
    } else {
        //instr 1
        char buf[32];
        sprintf(buf, "%hhu,%i", rd, imm);
        write_instr(lui(buf));

        //instr 2
        Instr_format_I instr;
        *(uint32_t *) &instr = 0;
        instr.opcode = ADDI;
        instr.rd = rd;
        instr.rs1 = rd;
        fill_imm_I(&instr, imm & 0x1FFF);
        return *(uint32_t *)&instr;
    }
}

uint32_t mv(char *param){
    NEW_INSTR(I);
    instr.opcode = ADDI;
    uint8_t rd, rs1;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs1);
    instr.rd = rd;
    instr.rs1 = rs1;
    return *(uint32_t *)&instr;
}

uint32_t neg(char *param){
    NEW_INSTR(R);
    instr.opcode = SUB;
    uint8_t rd, rs;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs);
    instr.rd = rd;
    instr.rs1 = 0;
    instr.rs2 = rs;
    return *(uint32_t *)&instr;
}

uint32_t not(char *param){
    NEW_INSTR(I);
    instr.opcode = XORI;
    uint8_t rd, rs1;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs1);
    instr.rd = rd;
    instr.rs1 = rs1;
    fill_imm_I(&instr, -1);
    return *(uint32_t *)&instr;
}

uint32_t seqz(char *param){
    NEW_INSTR(I);
    instr.opcode = SLTUI;
    uint8_t rd, rs;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs);
    instr.rd = rd;
    instr.rs1 = rs;
    fill_imm_I(&instr, 1);
    return *(uint32_t *)&instr;
}

uint32_t snez(char *param){
    NEW_INSTR(R);
    instr.opcode = SLTU;
    uint8_t rd, rs;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs);
    instr.rd = rd;
    instr.rs1 = 0;
    instr.rs2 = rs;
    return *(uint32_t *)&instr;
}

uint32_t sltz(char *param){
    NEW_INSTR(R);
    instr.opcode = SLT;
    uint8_t rd, rs;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs);
    instr.rd = rd;
    instr.rs1 = rs;
    instr.rs2 = 0;
    return *(uint32_t *)&instr;
}

uint32_t sgtz(char *param){
    NEW_INSTR(R);
    instr.opcode = SLT;
    uint8_t rd, rs;
    sscanf(param, "%hhu%*[ \n,]%hhu", &rd, &rs);
    instr.rd = rd;
    instr.rs1 = 0;
    instr.rs2 = rs;
    return *(uint32_t *)&instr;
}

uint32_t beqz(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BEQ;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = rs;
    instr.rs2 = 0;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}
uint32_t bnez(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BNE;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = rs;
    instr.rs2 = 0;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t blez(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGE;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = 0;
    instr.rs2 = rs;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t bgez(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGE;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = rs;
    instr.rs2 = 0;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t bltz(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLT;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = rs;
    instr.rs2 = 0;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t bgtz(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLT;
    uint8_t rs;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rs, &imm);
    instr.rs1 = 0;
    instr.rs2 = rs;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t bgt(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLT;
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%hhu%*[ \n,]%i", &rs1, &rs2, &imm);
    instr.rs1 = rs2;
    instr.rs2 = rs1;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}
uint32_t ble(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGE;
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%hhu%*[ \n,]%i", &rs1, &rs2, &imm);
    instr.rs1 = rs2;
    instr.rs2 = rs1;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}
uint32_t bgtu(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BLTU;
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%hhu%*[ \n,]%i", &rs1, &rs2, &imm);
    instr.rs1 = rs2;
    instr.rs2 = rs1;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t bleu(char *param){
    check_symbol(param);
    NEW_INSTR(S);
    instr.opcode = BGEU;
    uint8_t rs1, rs2;
    int32_t imm;
    sscanf(param, "%hhu%*[ \n,]%hhu%*[ \n,]%i", &rs1, &rs2, &imm);
    instr.rs1 = rs2;
    instr.rs2 = rs1;
    fill_imm_S(&instr, imm);
    return *(uint32_t *)&instr;
}

uint32_t pushw(char *param){
    write_instr(addi("3,3,-4"));
    char buf[16];
    sprintf(buf, "3,%s,0", param);
    return sw(buf);
}

uint32_t popw(char *param){
    char buf[16];
    sprintf(buf, "%s,3,0", param);
    write_instr(lw(buf));
    return addi("3,3,4");
}

uint32_t mkfm(char *param){
    write_instr(pushw("2"));
    return mv("2,3");
}

uint32_t pofm(char *param){
    write_instr(addi("3,2,4"));
    return lw("2,2,0");
}

uint32_t jump(char *param){
    if (!isdigit(param[0]) && param[0] != '-' && param[0] != '+'){
        uint32_t loc = ref_label(param);
        if (loc == LABEL_FILL_TEMP) loc = 0;
        sprintf(param, "%d", loc);
    }
    int32_t imm;
    sscanf(param, "%i", &imm);
    if (imm >> 18 == 0 || imm >> 18 == -1){//normal
        Instr_format_U instr;
        *(uint32_t *)&instr = 0;
        instr.opcode = JAL;
        instr.rd = 0;
        fill_imm_UJ(&instr, imm);
        return *(uint32_t *)&instr;
    } else {
        char buf[32];
        sprintf(buf, "4,%i", imm);
        write_instr(auipc(buf));

        Instr_format_I instr;
        *(uint32_t *) &instr = 0;
        instr.opcode = JALR;
        instr.rd = 0;
        instr.rs1 = 4;
        fill_imm_I(&instr, imm & 0x1FFF);
        return *(uint32_t *)&instr;
    }
}

uint32_t jumpr(char *param){
    uint8_t rs;
    sscanf(param, "%hhu", &rs);
    NEW_INSTR(I);
    instr.opcode = JALR;
    instr.rd = 0;
    instr.rs1 = rs;
    instr.imm = 0;
    return *(uint32_t *)&instr;
}

uint32_t call(char *param){
    if (!isdigit(param[0]) && param[0] != '-' && param[0] != '+'){
        uint32_t loc = ref_label(param);
        if (loc == LABEL_FILL_TEMP) loc = 0;
        sprintf(param, "%d", loc);
    }
    int32_t imm;
    sscanf(param, "%i", &imm);
    if (imm >> 18 == 0 || imm >> 18 == -1){//normal
        Instr_format_U instr;
        *(uint32_t *)&instr = 0;
        instr.opcode = JAL;
        instr.rd = 1;
        fill_imm_UJ(&instr, imm);
        return *(uint32_t *)&instr;
    } else {
        char buf[32];
        sprintf(buf, "4,%i", imm);
        write_instr(auipc(buf));

        Instr_format_I instr;
        *(uint32_t *) &instr = 0;
        instr.opcode = JALR;
        instr.rd = 1;
        instr.rs1 = 4;
        fill_imm_I(&instr, imm & 0x1FFF);
        return *(uint32_t *)&instr;
    }
}

uint32_t callr(char *param){
    uint8_t rs;
    sscanf(param, "%hhu", &rs);
    NEW_INSTR(I);
    instr.opcode = JALR;
    instr.rd = 1;
    instr.rs1 = rs;
    instr.imm = 0;
    return *(uint32_t *)&instr;
}

uint32_t ret(char *param){
    write_instr(pofm(NULL));
    NEW_INSTR(I);
    instr.opcode = JALR;
    instr.rd = 0;
    instr.rs1 = 1;
    instr.imm = 0;
    return *(uint32_t *)&instr;
}

uint32_t la(char *param){
    //la ?, @global
    if (strchr(param, '@') == NULL) perrorf_exit(0, "Format error: la %s\n", param);
    char name[64];
    uint8_t dest;
    sscanf(param, "%hhu%*[ \n,]@%s", &dest, name);
    int32_t offset = data_get(name);
    if (offset == GLOBAL_NOT_FOUND) perrorf_exit(1, "undeclared identifier: %s\n", name);
    sprintf(name, "%hhu,4,%d", dest, offset);
    return addi(name);
}

//other
uint32_t ecall(char *param) {
    NEW_INSTR(U);
    uint8_t rd;
    uint32_t imm;
    sscanf(param, "%hhu%*[ \n,]%i", &rd, &imm);
    instr.opcode = ECALL;
    instr.rd = rd;
    instr.imm = imm;
    return *(uint32_t *)&instr;
}