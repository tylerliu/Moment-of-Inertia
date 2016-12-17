//
//
//
//
//
//Uses little Endian for instr.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include "Execution.h"

FILE *in;
FILE *out;

uint32_t bytes_written;

//dictionary
const int length_op = 70;
char opname[70][7] = {"ADDI", "SLTI", "SLTUI", "ANDI", "ORI", "XORI", "SLLI", "SRLI", "SRAI", "ADD", "SUB", "SLT",
                      "SLTU", "AND", "OR", "XOR", "SLL", "SRL", "SRA", "MUL", "MULH", "MULHU", "MULHSU", "DIV", "DIVU",
                      "REM", "REMU", "LUI", "AUIPC", "JAL", "JALR", "BEQ", "BNE", "BLT", "BLTU", "BGE", "BGEU", "LW",
                      "LH", "LHU", "LB", "LBU", "SW", "SH", "SB", "FLW", "FLD", "FSW", "FSD", "FADD", "FSUB", "FMUL",
                      "FDIV", "FSQRT", "FCVT_D_W", "FCVT_D_WU", "FCVT_W_D", "FCVT_WU_D", "F_EQ", "F_LT", "F_LE",
                      "FMADD", "FMSUB", "FNMADD", "FNMSUB", "SCAN", "PRINT", "CALL", "RET", "REALLOC"};
uint32_t (*opdec[70])(char *) = {&addi, &slti, &sltui, &andi, &ori, &xori, &slli, &srli, &srai, &add, &sub, &slt, &sltu,
                                 &and, &or, &xor, &sll, &srl, &sra, &mul, &mulh, &mulhu, &mulhsu, &division, &divu, &rem,
                                 &remu, &lui, &auipc, &jal, &jalr, &beq, &bne, &blt, &bltu, &bge, &bgeu, &lw, &lh,
                                 &lhu, &lb, &lbu, &sw, &sh, &sb, &flw, &fld, &fsw, &fsd, &fadd, &fsub, &fmul, &fdiv,
                                 &fsqrt, &fcvt_d_w, &fcvt_d_wu, &fcvt_w_d, &fcvt_wu_d, &f_eq, &f_lt, &f_le, &fmadd,
                                 &fmsub, &fnmadd, &fnmsub, &scan, &print, &call, &ret, &reallocation};

int decode_line(){
    char buff[21];
    uint32_t instr = 0;
    if (!fgets(buff, 20, in)) return EOF;
    //printf("READ: %s\n", buff);

    //delete comment
    if (strstr(buff, "//") != NULL) {
        buff[strstr(buff, "//") - buff] = '\0';
        return 1;
    }

    for (int i = 0;buff[i]; i++){//capitalize
        buff[i] = (char) toupper(buff[i]);
    }

    for (int i = 0; i < length_op; i ++){
        if (!memcmp(buff, opname[i], strlen(opname[i]))){
            instr = (*opdec[i])(strchr(buff, ' ') + 1);
            break;
        }

    }

    fwrite(&instr, 4, 1, out);
    bytes_written ++;
    return 1;
}

int main(int argc, char *argv[]) {

    //if (strstr(argv[1], ".gnfc") == NULL) printf("Incorrect file suffix. \n");

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "wb");
    if ((!in) || (!out)){
        printf("Error: %s\n", strerror(errno));
        if (out) {
            fclose(out);
            remove(argv[2]);
        }
        return 1;
    }
    int32_t length = 0;
    fwrite(&length, 4, 1, out);

    fscanf(in, "%u\n", &length);
    fwrite(&length, 4, 1, out);

    while (decode_line() != EOF){};

    fseek(out, 0, SEEK_SET);
    fwrite(&bytes_written, 4, 1, out);
    fclose(in);
    fclose(out);
    return 0;
}
