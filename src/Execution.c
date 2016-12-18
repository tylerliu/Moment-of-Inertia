//
//  Execution.c
//  Inertia
//
//  Created by Tyler Liu on 2016/12/03.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//
//  execution function

#include "Execution.h"
#include "Instr_set.h"
#include <stdio.h>
#include <string.h>

// Integer Register-Immediate Instructions, type I
//OPIMM

uint32_t addi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = ADD;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slti(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = SLT;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltui(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = SLTU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t andi(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = AND;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t ori(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = OR;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xori(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = XOR;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t slli(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = SLL;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srli(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = SRL;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srai(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_IMM;
    instr.funct3 = SRL;
    parse_I(&instr, param);
    instr.imm0_11 += 0b010000000000;
    return *(uint32_t *)&instr;
}


//Integer Register-Register Operations, type R
//OP
uint32_t add(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = ADD;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sub(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SUB;
    parse_R(&instr, param);
    instr.funct7 = 0b0100000;
    return *(uint32_t *)&instr;
}

uint32_t slt(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SLT;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sltu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SLTU;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t and(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = AND;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t or(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = OR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t xor(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = XOR;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sll(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SLL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t srl(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SRL;
    parse_R(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sra(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = SRA;
    parse_R(&instr, param);
    instr.funct7 = 0b0100000;
    return *(uint32_t *)&instr;
}

uint32_t mul(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = MUL;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t mulh(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = MULH;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t mulhu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = MULHU;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t mulhsu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = MULHSU;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t division(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = DIV;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t divu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = DIVU;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t rem(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = REM;
    parse_R(&instr, param);
    instr.funct7 = 1;
    return *(uint32_t *)&instr;
}

uint32_t remu(char *param){
    Instr_format_R instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP;
    instr.funct3 = REMU;
    parse_R(&instr, param);
    instr.funct7 = 1;
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

//add upper immediate to pc, type U, add imm to pc, store in dest.
uint32_t auipc(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = AUIPC;
    parse_U(&instr, param);
    return *(uint32_t *)&instr;
}

//Unconditional jumps, type UJ, add immediate to pc.if dest = 0, plain jump. store pc+4 to dest after jump.
uint32_t jal(char *param){
    Instr_format_UJ instr;
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

//branch statements, type SB, shift of offest.
//BRANCH
uint32_t beq(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BEQ;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bne(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BNE;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t blt(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BLT;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bltu(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BLTU;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bge(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BGE;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t bgeu(char *param){
    Instr_format_SB instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = BRANCH;
    instr.funct3 = BGEU;
    parse_SB(&instr, param);
    return *(uint32_t *)&instr;
}

//load from int_memory, type I, The effective byte = s1 + IMM.
uint32_t lw(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD;
    instr.funct3 = LW;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lh(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD;
    instr.funct3 = LH;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lhu(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD;
    instr.funct3 = LHU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lb(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD;
    instr.funct3 = LB;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t lbu(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD;
    instr.funct3 = LBU;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t sw(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = STORE;
    instr.funct3 = SW;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sh(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = STORE;
    instr.funct3 = SH;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t sb(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = STORE;
    instr.funct3 = SB;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//RV32F/RV32D

//load from memory, type I, The effective byte = s1 + IMM.
uint32_t flw(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD_FP;
    instr.funct3 = FLT;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fld(char *param){
    Instr_format_I instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = LOAD_FP;
    instr.funct3 = DLE;
    parse_I(&instr, param);
    return *(uint32_t *)&instr;
}

//store to int_memory, type S, The effective byte = s1 + IMM.
uint32_t fsw(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = STORE_FP;
    instr.funct3 = FLT;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsd(char *param){
    Instr_format_S instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = STORE_FP;
    instr.funct3 = DLE;
    parse_S(&instr, param);
    return *(uint32_t *)&instr;
}

//FP_OP
uint32_t fadd(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FADD;
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsub(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FSUB;
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fmul(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FMUL;
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fdiv(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FDIV;
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fsqrt(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FSQRT;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_w(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCVT_fmt_int;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_d_wu(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCVT_fmt_int;
    strcat(param, ",1");
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_w_d(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCVT_int_fmt;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t fcvt_wu_d(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCVT_int_fmt;
    strcat(param, ",1");
    parse_R4OP(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t f_eq(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCMP;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    instr.funct3 = F_EQ;
    return *(uint32_t *)&instr;
}

uint32_t f_lt(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCMP;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    instr.funct3 = F_LT;
    return *(uint32_t *)&instr;
}

uint32_t f_le(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = OP_FP;
    instr.rs3 = FCMP;
    strcat(param, ",0");
    parse_R4OP(&instr, param);
    instr.funct3 = F_LE;
    return *(uint32_t *)&instr;
}


//rs1 * rs2 + rs3, type R4
uint32_t fmadd(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FMADD;
    parse_R4(&instr, param);
    return *(uint32_t *)&instr;
}
//rs1 * rs2 - rs3, type R4
uint32_t fmsub(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FMSUB;
    parse_R4(&instr, param);
    return *(uint32_t *)&instr;
}

//-(rs1 * rs2 + rs3), type R4
uint32_t fnmadd(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FNMADD;
    parse_R4(&instr, param);
    return *(uint32_t *)&instr;
}

//-(rs1 * rs2 - rs3), type R4
uint32_t fnmsub(char *param){
    Instr_format_R4 instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FNMSUB;
    parse_R4(&instr, param);
    return *(uint32_t *)&instr;
}

uint32_t scan(char *format){
    //TODO if length overflow
    uint8_t rd;
    sscanf(strrchr(format, ',') + 1, "%hhu", &rd);
    //printf("%u\n", rd);
    *strrchr(format, ',') = '\0';
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    uint32_t imm = 0;
    instr.opcode = IO;
    instr.rd = rd;
    uint32_t ptr = 1;
    if (format[0] == '%' & format[1] != '%'){
        if (strspn(format + ptr, "-+ 0#") != 0){
            switch(format[ptr]){
                case '-':
                    imm += 1 << 17;
                    break;
                case '+':
                    imm += 2 << 17;
                    break;
                case ' ':
                    imm += 3 << 17;
                    break;
                case '0':
                    imm += 4 << 17;
                    break;
                case '#':
                    imm += 5 << 17;
                    break;
            }
            ptr++;
        }

        if (strspn(format + ptr, "0123456789") != 0){//field length
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 13;
            ptr += strspn(format + ptr, "0123456789");
        }

        if (format[ptr] == '.'){//precision
            ptr++;
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 9;
            ptr+= strspn(format + ptr, "0123456789");
        }

        if (!memcmp(format+ptr, "hh", 2)){
            imm += 1 << 6;
            ptr += 2;
        }

        if (!memcmp(format+ptr, "ll", 2)){
            imm += 4 << 6;
            ptr += 2;
        }

        if (format[ptr] == 'h'){
            imm += 2 << 6;
            ptr++;
        }

        if (format[ptr] == 'l'){
            imm += 3 << 6;
            ptr++;
        }

        if (format[ptr] == 'L'){
            imm += 5 << 6;
            ptr++;
        }

        switch (format[ptr]){//type
            case 'd'://"d"
                break;
            case 'u'://"u"
                imm += 1 << 2;
                break;
            case 'f'://"f"
                imm += 2 << 2;
                break;
            case 'F'://"F"
                imm += 3 << 2;
                break;
            case 'e'://"e"
                imm += 4 << 2;
                break;
            case 'E'://"E"
                imm += 5 << 2;
                break;
            case 'g'://"g"
                imm += 6 << 2;
                break;
            case 'G'://"G"
                imm += 7 << 2;
                break;
            case 'x'://"x"
                imm += 8 << 2;
                break;
            case 'X'://"X"
                imm += 9 << 2;
                break;
            case 'o'://"o"
                imm += 10 << 2;
                break;
            case 'c'://"c"
                imm += 11 << 2;
                break;
            case 'a'://"a"
                imm += 12 << 2;
                break;
            case 'A'://"A"
                imm += 13 << 2;
                break;
            case 'i'://"i"
                imm += 14 << 2;
                break;
            default:
                break;
        }
    }
    else{
        char temp[3];
        temp[0] = temp[1] = temp[2] = '\0';
        for (int i = 0; i < 3; i++){
            if (format[i] == '\n' || format[i] == ' ') format[i] = 0;
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

        imm = (uint32_t)((unsigned char)temp[1] << 10) + ((unsigned char)temp[0] << 2) + 0b10;
    }
    instr.imm12_31 = imm;
    return *(uint32_t *)&instr;
}

uint32_t print(char *format){
    //TODO if length overflow
    uint8_t rd = 0;
    if (strrchr(format, ',') != NULL) sscanf(strrchr(format, ',') + 1, "%hhu", &rd);
    //printf("%u\n", rd);
    if (strrchr(format, ',') != NULL) *strrchr(format, ',') = '\0';
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    uint32_t imm = 0;
    instr.opcode = IO;
    instr.rd = rd;
    uint32_t ptr = 1;
    if (format[0] == '%' & format[1] != '%'){
        if (strspn(format + ptr, "-+ 0#") != 0){
            switch(format[ptr]){
                case '-':
                    imm += 1 << 17;
                    break;
                case '+':
                    imm += 2 << 17;
                    break;
                case ' ':
                    imm += 3 << 17;
                    break;
                case '0':
                    imm += 4 << 17;
                    break;
                case '#':
                    imm += 5 << 17;
                    break;
            }
            ptr++;
        }

        if (strspn(format + ptr, "0123456789") != 0){//field length
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 13;
            ptr += strspn(format + ptr, "0123456789");
        }

        if (format[ptr] == '.'){//precision
            ptr++;
            int i;
            sscanf(format+ptr, "%u", &i);
            imm += i << 9;
            ptr+= strspn(format + ptr, "0123456789");
        }

        if (!memcmp(format+ptr, "hh", 2)){
            imm += 1 << 6;
            ptr += 2;
        }

        if (!memcmp(format+ptr, "ll", 2)){
            imm += 4 << 6;
            ptr += 2;
        }

        if (format[ptr] == 'h'){
            imm += 2 << 6;
            ptr++;
        }

        if (format[ptr] == 'l'){
            imm += 3 << 6;
            ptr++;
        }

        if (format[ptr] == 'L'){
            imm += 5 << 6;
            ptr++;
        }

        switch (format[ptr]){//type
            case 'd'://"d"
                break;
            case 'u'://"u"
                imm += 1 << 2;
                break;
            case 'f'://"f"
                imm += 2 << 2;
                break;
            case 'F'://"F"
                imm += 3 << 2;
                break;
            case 'e'://"e"
                imm += 4 << 2;
                break;
            case 'E'://"E"
                imm += 5 << 2;
                break;
            case 'g'://"g"
                imm += 6 << 2;
                break;
            case 'G'://"G"
                imm += 7 << 2;
                break;
            case 'x'://"x"
                imm += 8 << 2;
                break;
            case 'X'://"X"
                imm += 9 << 2;
                break;
            case 'o'://"o"
                imm += 10 << 2;
                break;
            case 'c'://"c"
                imm += 11 << 2;
                break;
            case 'a'://"a"
                imm += 12 << 2;
                break;
            case 'A'://"A"
                imm += 13 << 2;
                break;
            case 'i'://"i"
                imm += 14 << 2;
                break;
            default:
                break;
        }
    }
    else{
        char temp[3];
        temp[0] = temp[1] = temp[2] = '\0';
        for (int i = 0; i < 3; i++){
            if (format[i] == '\n' || format[i] == ' ') format[i] = 0;
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

        imm = (uint32_t)((unsigned char)temp[1] << 10) + ((unsigned char)temp[0] << 2) + 0b10;
    }
    imm++;
    instr.imm12_31 = imm;
    return *(uint32_t *)&instr;
}

uint32_t call(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FUNC;
    instr.imm12_31 = 0;
    return *(uint32_t *)&instr;
}

uint32_t ret(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FUNC;
    instr.imm12_31 = 1;
    return *(uint32_t *)&instr;
}

uint32_t reallocation(char *param){
    Instr_format_U instr;
    *(uint32_t *)&instr = 0;
    instr.opcode = FUNC;
    instr.imm12_31 = 2;
    uint32_t i;
    sscanf(param, "%u", &i);
    instr.rd = i;
    return *(uint32_t *)&instr;
}