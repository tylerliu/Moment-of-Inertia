//
// Created by Tyler on 2017/07/31.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "Text.h"
#include "FileIO.h"
#include "Execution.h"
#include "string.h"

bool text_read; //whether text region is read

//dictionary
const int length_op = 98;
char opname[length_op][10] = {"ADDI", "SLTI", "SLTUI", "ANDI", "ORI", "XORI", "SLLI", "SRLI", "SRAI", "MULI", "DIVI", "DIVUI", "REMI", "REMUI",
                              "ADD", "SUB", "SLT", "SLTU", "AND", "OR", "XOR", "SLL", "SRL", "SRA", "MUL", "DIVISION", "DIVU", "REM",
                              "REMU", "LUI", "AUIPC", "JAL", "JALR", "BEQ", "BNE", "BLT", "BLTU", "BGE", "BGEU", "LW", "LH",
                              "LHU", "LB", "LBU", "SW", "SH", "SB", "FLW", "FLD", "FSW", "FSD", "FADD", "FSUB", "FMUL", "FDIV",
                              "FSQRT", "FCVT_D_W", "FCVT_D_WU", "FCVT_W_D", "FCVT_WU_D", "F_EQ", "F_LT", "F_LE", "FMV", "FNEG", "FABS",
                              "SCAN", "PRINT", "REALLOC", "EXIT",
        /*Pseudo-instructions*/
                              "NOP", "LI", "MV", "NEG", "NOT", "SEQZ", "SNEZ", "SLTZ", "SGTZ", "BEQZ", "BNEZ", "BLEZ", "BGEZ", "BLTZ", "BGTZ",
                              "BGT", "BLE", "BGTU", "BLEU", "PUSHW", "POPW", "MKFM", "POFM", "JUMP", "CALL", "JUMPR", "CALLR", "RET"};
uint32_t (*opdec[length_op])(char *) = {addi, slti, sltui, andi, ori, xori, slli, srli, srai, muli, divi, divui, remi, remui,
                                        add, sub, slt, sltu, and, or, xor, sll, srl, sra, mul, division, divu, rem,
                                        remu, lui, auipc, jal, jalr, beq, bne, blt, bltu, bge, bgeu, lw, lh,
                                        lhu, lb, lbu, sw, sh, sb, flw, fld, fsw, fsd, fadd, fsub, fmul, fdiv,
                                        fsqrt, fcvt_d_w, fcvt_d_wu, fcvt_w_d, fcvt_wu_d, f_eq, f_lt, f_le, fmv, fneg, Fabs,
                                        scan, print, reallocation, Exit,
        /*Pseudo-instructions*/
                                        nop, li, mv, neg, not, seqz, snez, sltz, sgtz, beqz, bnez, blez, bgez, bltz, bgtz,
                                        bgt, ble, bgtu, bleu, pushw, popw, mkfm, pofm, jump, call, jumpr, callr, ret};


void write_instr(uint32_t instr){
    //printf("bytes: %u, %s, 0x%08X\n", bytes_written, opname[instr & 0XFF], instr);
    write_int32(instr);
    bytes_written++;
}

void start_text(){
    if (text_read){
        fprintf(stderr, "Multiple Text region. Place check the assembly. \n");
        exit(1);
    }
    text_read = 1;
}

int decode_text_line(char *buff){
    char *ptr;
    //printf("READ: %s\n", buff);

    for (int i = 0;buff[i]; i++){//capitalize
        if (buff[i] == ' ')break;
        buff[i] = (char) toupper(buff[i]);
    }

    for (int i = 0; i < length_op; i ++){
        if (!memcmp(buff, opname[i], strlen(opname[i]))){
            ptr = strchr(buff, ' ');
            if (ptr != NULL)
                for (ptr ++; *ptr == ' ' || *ptr == '\t';ptr ++);
            write_instr((*opdec[i])(ptr));
            return 1;
        }

    }
    fprintf(stderr, "Unrecognizable text: %s\n", buff);
    return 1;
}

