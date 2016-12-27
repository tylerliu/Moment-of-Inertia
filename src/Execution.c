//
//  Execution.c
//  Inertia
//
//  Created by Tyler Liu on 2016/12/03.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//
//  execution function

#include "Execution.h"
#include <stdio.h>
#include <string.h>

//parse of IO functions
uint32_t parseIO(char *param);

// Integer Register-Immediate Instructions, type I

uint32_t addi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = ADDI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slti(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLTI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltui(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLTUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t andi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = ANDI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t ori(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = ORI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xori(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = XORI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slli(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLLI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srli(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SRLI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srai(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SRAI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t muli(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = MULI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = DIVI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divui(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = DIVUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = REMI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remui(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = REMUI;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//Integer Register-Register Operations, type R
//OP
uint32_t add(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = ADD;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sub(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SUB;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slt(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLT;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLTU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t and(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = AND;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t or(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xor(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = XOR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sll(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SLL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srl(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SRL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sra(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SRA;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t mul(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = MUL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t division(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = DIV;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t divu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = DIVU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t rem(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = REM;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t remu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = REMU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

//load upper immediate, type U, load imm to dest.
uint32_t lui(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LUI;
    parse_U(&instr, param);
    return *(uint32_t *)&instr;
}

//Unconditional jumps, type U, add immediate to pc.if dest = 0, plain jump. store pc+4 to dest after jump.
uint32_t jal(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = JAL;
    parse_UJ(&instr, param);
    return *(uint32_t *)&instr;
}

//jump and link register, type I, store pc+4 to dest after jump.
uint32_t jalr(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = JALR;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//branch statements, type S, shift of offest.
//BRANCH
uint32_t beq(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BEQ;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bne(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;   
    instr.opcode = BNE;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t blt(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BLT;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bltu(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BLTU;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bge(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BGE;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bgeu(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BGEU;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//load from int_memory, type I, The effective byte = s1 + IMM.
uint32_t lw(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LW;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lh(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LH;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lhu(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LHU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lb(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LB;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lbu(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LBU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t sw(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SW;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sh(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SH;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sb(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SB;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//RV32F/RV32D

//load from memory, type I, The effective byte = s1 + IMM.
uint32_t flw(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FLW;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fld(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FLD;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t fsw(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FSW;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsd(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FSD;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//FP_OP
uint32_t fadd(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FADD;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsub(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FSUB;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fmul(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FMUL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fdiv(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FDIV;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsqrt(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FSQRT;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_w(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FCVT_D_W;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_wu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FCVT_D_WU;
    strcat(param, ",1");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_w_d(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FCVT_W_D;
    strcat(param, ",0");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_wu_d(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FCVT_WU_D;
    strcat(param, ",1");
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t f_eq(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    parse_R(&instr, param);
    instr.opcode = F_EQ;
    return *(uint32_t *)&instr;
}

uint32_t f_lt(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    parse_R(&instr, param);
    instr.opcode = F_LT;
    return *(uint32_t *)&instr;
}

uint32_t f_le(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    parse_R(&instr, param);
    instr.opcode = F_LE;
    return *(uint32_t *)&instr;
}

uint32_t scan(char *format){
    //TODO if length overflow
    uint8_t rd;
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = SCAN;
    instr.imm = parseIO(format);
    if (!(instr.imm & 1)) {
        sscanf(strrchr(format, ',') + 1, "%hhu", &rd);
        instr.rd = rd;
    }

    return *(uint32_t *)&instr;
}

uint32_t print(char *format){
    uint8_t rd;
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = PRINT;
    instr.imm = parseIO(format);
    if (!(instr.imm & 1)) {
        sscanf(strrchr(format, ',') + 1, "%hhu", &rd);
        instr.rd = rd;
    }

    return *(uint32_t *)&instr;
}
uint32_t parseIO(char *format){
    //TODO if length overflow
    uint32_t imm = 0;
    if (format[0] == '%' & format[1] != '%'){
        uint32_t ptr = 1;
        if (strspn(format + ptr, "-+ 0#") != 0){
            switch(format[ptr]){
                case '-':
                    imm += 1 << 16;
                    break;
                case '+':
                    imm += 2 << 16;
                    break;
                case ' ':
                    imm += 3 << 16;
                    break;
                case '0':
                    imm += 4 << 16;
                    break;
                case '#':
                    imm += 5 << 16;
                    break;
                default:
                    break;
            }
            ptr++;
        }

        if (strspn(format + ptr, "0123456789") != 0){//field length
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 12;
            ptr += strspn(format + ptr, "0123456789");
        }

        if (format[ptr] == '.'){//precision
            ptr++;
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 8;
            ptr+= strspn(format + ptr, "0123456789");
        }

        if (!memcmp(format+ptr, "hh", 2)){
            imm += 1 << 5;
            ptr += 2;
        }

        if (!memcmp(format+ptr, "ll", 2)){
            imm += 4 << 5;
            ptr += 2;
        }

        if (format[ptr] == 'h'){
            imm += 2 << 5;
            ptr++;
        }

        if (format[ptr] == 'l'){
            imm += 3 << 5;
            ptr++;
        }

        if (format[ptr] == 'L'){
            imm += 5 << 5;
            ptr++;
        }

        switch (format[ptr]){//type
            case 'd'://"d"
                break;
            case 'u'://"u"
                imm += 1 << 1;
                break;
            case 'f'://"f"
                imm += 2 << 1;
                break;
            case 'F'://"F"
                imm += 3 << 1;
                break;
            case 'e'://"e"
                imm += 4 << 1;
                break;
            case 'E'://"E"
                imm += 5 << 1;
                break;
            case 'g'://"g"
                imm += 6 << 1;
                break;
            case 'G'://"G"
                imm += 7 << 1;
                break;
            case 'x'://"x"
                imm += 8 << 1;
                break;
            case 'X'://"X"
                imm += 9 << 1;
                break;
            case 'o'://"o"
                imm += 10 << 1;
                break;
            case 'c'://"c"
                imm += 11 << 1;
                break;
            case 'a'://"a"
                imm += 12 << 1;
                break;
            case 'A'://"A"
                imm += 13 << 1;
                break;
            case 'i'://"i"
                imm += 14 << 1;
                break;
            default:
                break;
        }
    }
    else{
        char temp[3];
        temp[0] = temp[1] = temp[2] = '\0';
        for (int i = 0; i < 3; i++){
            if (format[i] == '\n') format[i] = 0;
        }
        int i = 0;
        if (format[i] != '%' && format[i] != '\\'){
            temp[0] = format[i];
            i++;
        }
        else{
            if(format[i] == '%'){
                temp[0] = '%';
            }
            else{
                switch (format[i+1]){
                    case 'n':
                        temp[0] = '\n';
                        break;
                    case '\\':
                        temp[0] = '\\';
                        break;
                    case 'a':
                        temp[0] = '\a';
                        break;
                    case 'b':
                        temp[0] = '\b';
                        break;
                    case 't':
                        temp[0] = '\t';
                        break;
                    case 'r':
                        temp[0] = '\r';
                        break;
                    case 'f':
                        temp[0] = '\f';
                        break;
                    default:
                        break;
                }
            }
            i += 2;
        }

        if (format[i] != '%' && format[i] != '\\'){
            temp[1] = format[i];
        }
        else{
            if(format[i] == '%'){
                temp[1] = '%';
            }
            else{
                switch (format[i+1]){
                    case 'n':
                        temp[1] = '\n';
                        break;
                    case '\\':
                        temp[1] = '\\';
                        break;
                    case 'a':
                        temp[1] = '\a';
                        break;
                    case 'b':
                        temp[1] = '\b';
                        break;
                    case 't':
                        temp[1] = '\t';
                        break;
                    case 'r':
                        temp[1] = '\r';
                        break;
                    case 'f':
                        temp[1] = '\f';
                        break;
                    default:
                        break;
                }
            }
        }

        imm = (uint32_t)((unsigned char)temp[1] << 10) + ((unsigned char)temp[0] << 2) + 1;
    }
    return imm;
}

uint32_t call(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = CALL;
    parse_UJ(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t callr(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = CALLR;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t ret(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = RET;
    return *(uint32_t *)&instr;
}

uint32_t reallocation(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = REALLOC;
    uint32_t i;
    sscanf(param, "%u", &i);
    instr.rd = i;
    return *(uint32_t *)&instr;
}

uint32_t Exit(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = EXIT;
    return *(uint32_t *)&instr;
}