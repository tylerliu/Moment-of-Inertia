//
// Created by Tyler on 2017/07/31.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "fileIO.h"
#include "text/text_instr.h"
#include "string.h"
#include "text/label.h"

bool text_read; //whether text region is read

//dictionary
const int length_op = 96;
char opname[length_op][10] = {"ADDI", "SLTI", "SLTUI", "ANDI", "ORI", "XORI", "SLLI", "SRLI", "SRAI", "MULI", "DIVI", "DIVUI", "REMI", "REMUI",
                              "ADD", "SUB", "SLT", "SLTU", "AND", "OR", "XOR", "SLL", "SRL", "SRA", "MUL", "DIVISION", "DIVU", "REM",
                              "REMU", "LUI", "AUIPC", "JAL", "JALR", "BEQ", "BNE", "BLT", "BLTU", "BGE", "BGEU", "LW", "LH",
                              "LHU", "LB", "LBU", "SW", "SH", "SB", "FLW", "FLD", "FSW", "FSD", "FADD", "FSUB", "FMUL", "FDIV",
                              "FSQRT", "FCVT_D_W", "FCVT_D_WU", "FCVT_W_D", "FCVT_WU_D", "F_EQ", "F_LT", "F_LE", "FMV", "FNEG", "FABS",
                              "ECALL",
        /*Pseudo-instructions*/
                              "NOP", "LI", "MV", "NEG", "NOT", "SEQZ", "SNEZ", "SLTZ", "SGTZ", "BEQZ", "BNEZ", "BLEZ", "BGEZ", "BLTZ", "BGTZ",
                              "BGT", "BLE", "BGTU", "BLEU", "PUSHW", "POPW", "MKFM", "POFM", "JUMP", "CALL", "JUMPR", "CALLR", "RET", "LA"};
uint32_t (*opdec[length_op])(char *) = {addi, slti, sltui, andi, ori, xori, slli, srli, srai, muli, divi, divui, remi, remui,
                                        add, sub, slt, sltu, and, or, xor, sll, srl, sra, mul, division, divu, rem,
                                        remu, lui, auipc, jal, jalr, beq, bne, blt, bltu, bge, bgeu, lw, lh,
                                        lhu, lb, lbu, sw, sh, sb, flw, fld, fsw, fsd, fadd, fsub, fmul, fdiv,
                                        fsqrt, fcvt_d_w, fcvt_d_wu, fcvt_w_d, fcvt_wu_d, f_eq, f_lt, f_le, fmv, fneg, Fabs,
                                        ecall,
        /*Pseudo-instructions*/
                                        nop, li, mv, neg, not, seqz, snez, sltz, sgtz, beqz, bnez, blez, bgez, bltz, bgtz,
                                        bgt, ble, bgtu, bleu, pushw, popw, mkfm, pofm, jump, call, jumpr, callr, ret, la};

uint32_t text_len = 256;
uint32_t text_written;
uint32_t *text_area;

void write_instr(uint32_t instr){
    //printf("bytes: %u, %s, 0x%08X\n", bytes_written, opname[instr & 0XFF], instr);
    if (text_written == text_len){
        text_len <<= 1;
        text_area = realloc(text_area, text_len * sizeof(uint32_t));
    }
    text_area[text_written] = instr;
    text_written++;
}

uint32_t get_instr(uint32_t loc){
    return text_area[loc];
}

void set_instr(uint32_t loc, uint32_t instr){
    text_area[loc] = instr;
}

uint32_t get_text_loc(){
    return text_written;
}

void start_text(){
    if (text_read){
        fprintf(stderr, "Multiple Text region. Place check the assembly. \n");
        exit(1);
    }
    text_area = malloc(text_len * sizeof(uint32_t));
    label_init();
    text_read = 1;
}

void decode_text_line(char *buff){
    //printf("READ: %s\n", buff);

    if (strchr(buff, ':') != NULL){
        *strchr(buff, ':') = 0;
        new_label(buff);
        buff = skip_space(buff + strlen(buff) + 1);
    }

    if (*buff == 0) return;

    for (int i = 0; i < length_op; i ++){
        if (startwith_incensitive(buff, opname[i])){
            write_instr((*opdec[i])(skip_space(buff + strlen(opname[i]))));
            return;
        }

    }
    fprintf(stderr, "Unrecognizable text: %s\n", buff);
    return;
}

void end_text(){

}

void write_text(){
    write_int32(text_written);
    write_segment(text_written * sizeof(uint32_t), text_area);
    label_end();
    free(text_area);
}

void text_force_exit(){
    label_force_exit();
    free(text_area);
}

