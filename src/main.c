#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define INERTIA_ADD 0x0 // Addition
#define INERTIA_DIV 0x1 // Division
#define INERTIA_MUL 0x2 // Multiplication

#define INERTIA_LTN 0x3 // Less Than
#define INERTIA_EQL 0x4 // Equal To
#define INERTIA_AND 0x5 // Bitwise AND
#define INERTIA_NOT 0x6 // Bitwise NOT
#define INERTIA_OR 0x7  // Bitwise OR
#define INERTIA_INC 0x8 // Increase by 1
#define INERTIA_DEC 0x9 // Decrease by 1

#define INERTIA_PRINT 0xA // Print to stdout
#define INERTIA_LOAD 0xB // Load value
#define INERTIA_GOTO 0xC //goto
#define INERTIA_IF 0xD //if par1 == false, skip to par2
#define INERTIA_RETURN 0xE //return
#define INERTIA_CALL 0xF // call function

typedef struct {
    uint32_t instr_num;
    char tpar[3];
    uint32_t par[3];
}instr_set;

typedef struct {
    int used;//1 if used
    uint32_t loc;//location
}go_link;

typedef struct{
    int type; //0 as if, 1 as while
    uint32_t instr_num;
    int par; //for while's second link, and if link
    uint32_t loc; //fpr while's first link
}loop_cond_record;

typedef struct{
    uint32_t loop_num;
    uint32_t instr_num;
}loop_break_record;

FILE *in;
FILE *out;

uint32_t bytes_written;

uint32_t len_instrs = 1024;
uint32_t used_instrs;
instr_set *instrs;

uint32_t len_links = 1024;
go_link *links;

uint32_t len_recs = 8;
uint32_t recs_count;
loop_cond_record * records;

uint32_t len_breaks = 8;
uint32_t breaks_count;
loop_break_record * break_recs;

void new_instr(uint32_t instr_num, char tpar[3], uint32_t par[3]){
    if (len_instrs == used_instrs){
        len_instrs <<= 1;
        instrs = (instr_set *)realloc(instrs, len_instrs * sizeof(instr_set));
        if (!instrs){
            printf("Failed to allocate\n");
            exit(1);
        }
    }

    instrs[used_instrs].instr_num = instr_num;
    instrs[used_instrs].tpar[0] = tpar[0];
    instrs[used_instrs].tpar[1] = tpar[1];
    instrs[used_instrs].tpar[2] = tpar[2];
    instrs[used_instrs].par[0] = par[0];
    instrs[used_instrs].par[1] = par[1];
    instrs[used_instrs].par[2] = par[2];
    bytes_written += (2 + (tpar[0] == '#' || tpar[0] == 'P') + (tpar[1] == '#'|| tpar[1] == 'P') + (tpar[2] == '#'|| tpar[2] == 'P'));
    used_instrs ++;
}

void new_link(uint32_t name, uint32_t loc){
    if (name >= len_links){
        len_links = name + 10;
        links = (go_link *)realloc(links, len_links * sizeof(go_link));
        if (!links){
            printf("Failed to allocate\n");
            exit(1);
        }
    }

    links[name].used = 1;
    links[name].loc = loc;
}

void new_rec(int type){
    if (recs_count == len_recs){
        len_recs <<=1;
        records = (loop_cond_record *)realloc(records, len_recs * sizeof(loop_cond_record));
        if (!records){
            printf("Failed to allocate\n");
            exit(1);
        }
    }
    records[recs_count].type = type;
    recs_count ++;
}

void new_break(uint32_t loop_num, uint32_t instr_num){
    if (breaks_count == len_breaks){
        len_breaks <<=1;
        break_recs = (loop_break_record *)realloc(break_recs, len_breaks * sizeof(loop_break_record));
        if (!records){
            printf("Failed to allocate\n");
            exit(1);
        }
    }

    break_recs[breaks_count].loop_num = loop_num;
    break_recs[breaks_count].instr_num = instr_num;
}

void flush_rec(){
    recs_count --;
    if (records[recs_count].type == 0){//if
        instrs[records[recs_count].instr_num].par[records[recs_count].par] = bytes_written;
    }
    if (records[recs_count].type == 1){//while
        char par1[3] = {'#', '@', '@'};
        uint32_t par2[3] = {records[recs_count].loc, 0, 0};
        new_instr(INERTIA_GOTO, par1, par2);
        instrs[records[recs_count].instr_num].par[records[recs_count].par] = bytes_written;

        //break release
        while(breaks_count > 0 && break_recs[breaks_count - 1].loop_num == recs_count){
            instrs[break_recs[breaks_count - 1].instr_num].par[0] = bytes_written;//make break
            breaks_count --;
        }
    }
}

void loop_continue(){

    //find last loop
    uint32_t temp = recs_count - 1;
    while(records[temp].type != 1){
        temp --;
    }
    char par1[3] = {'#', '@', '@'};
    uint32_t par2[3] = {records[temp].loc, 0, 0};
    new_instr(INERTIA_GOTO, par1, par2);

}

void loop_break(){
    //find last loop
    uint32_t temp = recs_count - 1;
    while(records[temp].type != 1){
        temp --;
    }
    char par1[3] = {'#', '@', '@'};
    uint32_t par2[3] = {0, 0, 0};
    new_instr(INERTIA_GOTO, par1, par2);
    new_break(temp, used_instrs - 1);
}

void make_links(){
    for (int i = 0; i < used_instrs; i++){
        for (int j = 0; j < 3; j ++){
            if (instrs[i].tpar[j] == 'P'){
                if (!links[instrs[i].par[j]].used) {
                    printf("goto label %d cannot be located", instrs[i].par[j]);
                    break;
                }
                instrs[i].par[j] = links[instrs[i].par[j]].loc;
                instrs[i].tpar[j] = '#';
            }
        }
    }
};

void fputu(uint32_t a){
    fputc((a >> 24), out);
    fputc((a >> 16) & 255, out);
    fputc((a >> 8) & 255, out);
    fputc(a & 255, out);
}

int get_type(uint32_t num, int index){
    switch(instrs[num].tpar[index]){
        case '@':
            return 0;
        case 'R':
            return 1;
        case '#':
            return 2;
        case '*':
            return 3;
        default:
            printf("Warning: incorrect argument type at instruction %d, argument %d", num + 1, index + 1);
            return -1;
    }
}

void put_instr (uint32_t num){
    fputc(((instrs[num].instr_num & 15) << 4) + (get_type(num, 0) << 2)
          +get_type(num, 1), out);
    fputc((get_type(num, 2) << 6) +
                  (((get_type(num, 0) == 1 || get_type(num, 0) == 3 ? instrs[num].par[0]:0) & 3) << 4) +
                  (((get_type(num, 1) == 1 || get_type(num, 1) == 3 ? instrs[num].par[1]:0) & 3) << 2) +
                  (((get_type(num, 2) == 1 || get_type(num, 2) == 3 ? instrs[num].par[2]:0) & 3)), out);
    fputc((instrs[num].tpar[0] == '@'? instrs[num].par[0]:0) >> 8, out);
    fputc((instrs[num].tpar[0] == '@'? instrs[num].par[0]:0), out);
    fputc((instrs[num].tpar[1] == '@'? instrs[num].par[1]:0) >> 8, out);
    fputc((instrs[num].tpar[1] == '@'? instrs[num].par[1]:0), out);
    fputc((instrs[num].tpar[2] == '@'? instrs[num].par[2]:0) >> 8, out);
    fputc((instrs[num].tpar[2] == '@'? instrs[num].par[2]:0), out);
    if (instrs[num].tpar[0] == '#')fputu(instrs[num].par[0]);
    if (instrs[num].tpar[1] == '#')fputu(instrs[num].par[1]);
    if (instrs[num].tpar[2] == '#')fputu(instrs[num].par[2]);
    
    //printf("%d, %d %c%d %c%d %c%d\n", num, instrs[num].instr_num, instrs[num].tpar[0], instrs[num].par[0], instrs[num].tpar[1], instrs[num].par[1], instrs[num].tpar[2], instrs[num].par[2]);

}

void decode_add(char *tpar, uint32_t *par){
    char c;
    uint32_t t;
    if (fscanf(in, " %c%u", &c,&t) == EOF) return;
    //printf("READADD: %c %u\n", c,t);
    c = (char) toupper(c);
    *tpar = c;
    *par = t;
}

int decode_line(){
    char buff[15];
    uint32_t name = 0;
    if (fscanf(in, "%s", buff) == EOF) return EOF;
    //printf("READ: %s\n", buff);

    //delete comment
    if (strstr(buff, "//") != NULL) {
        buff[strstr(buff, "//") - buff] = '\0';
        int c = '0';
        while (c != '\n' && c >= 0) {
            c = fgetc(in);
        } //skip a line
        printf("skip line\n");
        return 1;
    }

    for (int i = 0;buff[i]; i++){//capitalize
        buff[i] = (char) toupper(buff[i]);
    }
    if (buff[0] >= '0' && buff[0] <= '9') {//goto label
        name =(uint32_t) atoi(buff);
        new_link(name, bytes_written);//place now
        //printf("%d %d\n", name, bytes_written);
        return 1;
    }

    //cond/loop statements
    if (!strcmp(buff, "WHILE") || !strcmp(buff, "COND") || !strcmp(buff, "DO") || !strcmp(buff, "END")){
        if (!strcmp(buff, "WHILE")) {
            new_rec(1);
            records[recs_count - 1].loc = bytes_written;
        }

        if (!strcmp(buff, "COND")){
            new_rec(0);
            char tpar[3] = {'@', '#', '@'};
            uint32_t par[3] = {0, 0, 0};
            decode_add(&tpar[0], &par[0]); //get first parameter
            new_instr(INERTIA_IF, tpar, par);
            records[recs_count - 1].instr_num = used_instrs - 1;
            records[recs_count - 1].par = 1;
        }

        if (!strcmp(buff, "DO")){
            char tpar[3] = {'@', '#', '@'};
            uint32_t par[3] = {0, 0, 0};
            decode_add(&tpar[0], &par[0]);
            new_instr(INERTIA_IF, tpar, par);
            records[recs_count - 1].instr_num = used_instrs - 1;
            records[recs_count - 1].par = 1;
        }

        if (!strcmp(buff, "END")){
            flush_rec();
        }

        return 1;
    }

    //name used as instr
    if (!strcmp(buff, "ADD")) name = INERTIA_ADD;
    if (!strcmp(buff, "DIV")) name = INERTIA_DIV;
    if (!strcmp(buff, "MUL")) name = INERTIA_MUL;
    if (!strcmp(buff, "LTN")) name = INERTIA_LTN;
    if (!strcmp(buff, "EQL")) name = INERTIA_EQL;
    if (!strcmp(buff, "AND")) name = INERTIA_AND;
    if (!strcmp(buff, "NOT")) name = INERTIA_NOT;
    if (!strcmp(buff, "OR")) name = INERTIA_OR;
    if (!strcmp(buff, "INC")) name = INERTIA_INC;
    if (!strcmp(buff, "DEC")) name = INERTIA_DEC;
    if (!strcmp(buff, "PRINT")) name = INERTIA_PRINT;
    if (!strcmp(buff, "LOAD")) name = INERTIA_LOAD;
    if (!strcmp(buff, "GOTO")) name = INERTIA_GOTO;
    if (!strcmp(buff, "IF")) name = INERTIA_IF;
    if (!strcmp(buff, "RETURN")) name = INERTIA_RETURN;
    if (!strcmp(buff, "CALL")) name = INERTIA_CALL;

    char tpar[3] = {'@', '@', '@'};
    uint32_t par[3] = {0, 0, 0};

    switch (name){
        case 0 ... 5: // three par
        case 7:
            decode_add(&tpar[0], &par[0]);
            decode_add(&tpar[1], &par[1]);
            decode_add(&tpar[2], &par[2]);
            break;
        case 6: //two par
        case 11:
        case 13:
            decode_add(&tpar[0], &par[0]);
            decode_add(&tpar[1], &par[1]);
            break;
        case 8 ... 10://one par
        case 12:
        case 15:
            decode_add(&tpar[0], &par[0]);
            break;
        //no par, do nothing
        default:break;
    }

    new_instr(name, tpar, par);

    return 1;
}

int main(int argc, char *argv[]) {

    instrs = (instr_set *)malloc(len_instrs * sizeof(instr_set));
    links = (go_link *)malloc(len_links * sizeof(go_link));
    records = (loop_cond_record *)malloc(len_recs * sizeof(loop_cond_record));
    break_recs = (loop_break_record *)malloc(len_breaks * sizeof(loop_break_record));
    if ((!instrs) || (!links) || (!records) || (!break_recs)){
        printf("Failed to allocate\n");
        return 1;
    }

    //if (strstr(argv[1], ".gnfc") == NULL) printf("Incorrect file suffix. \n");

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "wb");
    if ((!in) || (!out)){
        printf("Failed to read file\n");
        if (out) {
            fclose(out);
            remove(argv[2]);
        }
        return 1;
    }


    while (decode_line() != EOF){};

    fputu(bytes_written);
    make_links();
    for (uint32_t i = 0; i < used_instrs; i ++){
        put_instr(i);
    }

    fclose(in);
    fclose(out);
    free(instrs);
    free(links);
    free(records);
    free(break_recs);
    return 0;
}
