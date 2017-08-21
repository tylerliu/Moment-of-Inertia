//
//  Execution.h
//  Inertia
//
//  Created by Tyler Liu on 2016/12/03.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//
//  execution function

#ifndef _Execution_h
#define _Execution_h

#include "Instr_set.h"
//for float NaN/Infinity/rounding mode
#include <math.h>

//Integer Register-Immediate Instructions, type I
//OPIMM
uint32_t addi(char *param);
uint32_t slti(char *param);
uint32_t sltui(char *param);
uint32_t andi(char *param);
uint32_t ori(char *param);
uint32_t xori(char *param);
uint32_t slli(char *param);
uint32_t srli(char *param);
uint32_t srai(char *param);
uint32_t muli(char *param);
uint32_t divi(char *param);
uint32_t divui(char *param);
uint32_t remi(char *param);
uint32_t remui(char *param);

//Integer Register-Register Operations, type R
//OP
uint32_t add(char *param);
uint32_t sub(char *param);
uint32_t slt(char *param);
uint32_t sltu(char *param);
uint32_t and(char *param);
uint32_t or(char *param);
uint32_t xor(char *param);
uint32_t sll(char *param);
uint32_t srl(char *param);
uint32_t sra(char *param);
uint32_t mul(char *param);
uint32_t division(char *param);
uint32_t divu(char *param);
uint32_t rem(char *param);
uint32_t remu(char *param);

uint32_t lui(char *param);   //load upper immediate, type U, load imm to dest.
uint32_t auipc(char *param); //add upper immediate to pc, type U, load imm + pc to dest.
uint32_t jal(char *param);    //Unconditional jumps, type UJ, add immediate to pc.if dest = 0, plain jump. store pc+4 to rd after jump.
uint32_t jalr(char *param);   //jump and link register, type I, store pc+4 to rd after jump

//branch statements, type S, shift of offest.
//BRANCH
uint32_t beq(char *param);
uint32_t bne(char *param);
uint32_t blt(char *param);
uint32_t bltu(char *param);
uint32_t bge(char *param);
uint32_t bgeu(char *param);

//load from memory, type I, The effective byte = s1 + IMM.
//LOAD
uint32_t lw(char *param);
uint32_t lh(char *param);
uint32_t lhu(char *param);
uint32_t lb(char *param);
uint32_t lbu(char *param);

//store to memory, type S, The effective byte = s1 + IMM.
//STORE
uint32_t sw(char *param);
uint32_t sh(char *param);
uint32_t sb(char *param);

//RV32F/RV32D
//load from memory, type I, The effective byte = s1 + IMM.
//LOAD_FP
uint32_t flw(char *param);
uint32_t fld(char *param);

//store to memory, type S, The effective byte = s1 + IMM.
//STORE_FP
uint32_t fsw(char *param);
uint32_t fsd(char *param);

//OP_FP
uint32_t fadd(char *param);
uint32_t fsub(char *param);
uint32_t fmul(char *param);
uint32_t fdiv(char *param);
uint32_t fsqrt(char *param);
uint32_t fcvt_d_w(char *param);
uint32_t fcvt_d_wu(char *param);
uint32_t fcvt_w_d(char *param);
uint32_t fcvt_wu_d(char *param);
uint32_t f_eq(char *param);
uint32_t f_lt(char *param);
uint32_t f_le(char *param);
uint32_t fmv(char *param);
uint32_t fneg(char *param);
uint32_t Fabs(char *param);

//Pseudo-instructions
uint32_t nop(char *param);
uint32_t li(char *param);
uint32_t mv(char *param);
uint32_t neg(char *param);
uint32_t not(char *param);
uint32_t seqz(char *param);
uint32_t snez(char *param);
uint32_t sltz(char *param);
uint32_t sgtz(char *param);

uint32_t beqz(char *param);
uint32_t bnez(char *param);
uint32_t blez(char *param);
uint32_t bgez(char *param);
uint32_t bltz(char *param);
uint32_t bgtz(char *param);

uint32_t bgt(char *param);
uint32_t ble(char *param);
uint32_t bgtu(char *param);
uint32_t bleu(char *param);

uint32_t pushw(char *param);
uint32_t popw(char *param);
uint32_t mkfm(char *param);
uint32_t pofm(char *param);

uint32_t jump(char *param);
uint32_t call(char *param);
uint32_t jumpr(char *param);
uint32_t callr(char *param);
uint32_t ret(char *param);

uint32_t la(char *param);

//IO
uint32_t scan(char *format);
uint32_t print(char *format);

uint32_t reallocation(char *param);
uint32_t Exit(char *param);
#endif /* Execution.h */