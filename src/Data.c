//
// Created by Tyler on 2017/08/01.
//

#include "Data.h"
#include "fileIO.h"
#include "Hash.h"
#include "error.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define GLOBAL_MIN -8192
#define GLOBAL_MAX 8191

const char type_name[8][10] = {".asciiz", ".ascii", ".byte", ".half", ".word", ".float", ".double", ".space"};
const char esc[23] = {"a\ab\bf\fn\nr\rt\tv\v\\\\''\"\"??"};

unsigned int data_read; //whether data region is read

uint32_t initd; //size of data that is not initialized
uint32_t uninitd;

uint32_t step; //1 as can add more, 2 as need more data, 0 as cannot add
char cur_name[64];
uint32_t cur_type;

uint32_t glb_len = 512;
void *global;

void start_data(){
    if (data_read)
        perror_exit(1, "Multiple Data region. Place check the assembly.\n");
    data_read = 1;

    //initialize global area
    global = malloc(glb_len);
}

void add_to_global(uint32_t len, const void *seg){
    //printf("%02X%02X%02X%02X\n", *(int8_t *)seg, *(int8_t *)(seg + 1), *(int8_t *)(seg + 2), *(int8_t *)(seg + 3));
    if (initd + len > glb_len){
        glb_len *= 2;
        global = realloc(global,glb_len);
    }
    memcpy(global + initd, seg, len);
    initd += len;
}

void align_global(){
    uint32_t temp = 0;
    add_to_global(((initd >> 2) << 2) + 4 - initd, &temp);
}

char *read_string(char *line){
    if (line[0] != '"')perrorf_exit(0, "not string: %s\n", line);
    line++;

    if (cur_type == ASCIIZ && step == 1) initd --;

    char k = 0; //temp

    while (strchr(line, '\\') != NULL && strchr(line, '\\') < strchr(line, '"')){
        add_to_global((uint32_t) (strchr(line, '\\') - line), line);
        line = strchr(line, '\\');

        k = 0;
        for (int i = 0; i <= 20;i += 2){
            if (line[1] == esc[i]){
                add_to_global(1, &esc[i + 1]);
                line += 2;
                k = 1;
                break;
            }
        }
        if (k == 1) break;


        //unicode or hex?
        if (line[1] >= '0' && line[1] <= '7' && line[2] >= '0' && line[2] <= '7' && line[3] >= '0' && line[3] <= '7' ){
            //oct
            k = (char) (((line[1] - '0') << 6) + ((line[2] - '0') << 3) + (line[3] - '0'));
            add_to_global(1, &k);
            line += 4;
            break;
        }

        if (line[1] == 'x' && isxdigit(line[2]) && isxdigit(line[3])){
            //hex
            k = (char) (((isdigit(line[2]) ? line[2] - '0' : isupper(line[2]) ? line[2] - 'A' + 10 : line[2] - 'a' + 10) << 4)
                     + (isdigit(line[3]) ? line[3] - '0' : isupper(line[3]) ? line[3] - 'A' + 10 : line[3] - 'a' + 10));
            add_to_global(1, &k);
            line += 4;
            break;
        }

        perrorf_exit(1, "failed to recognize escape sequence: %s\n", line);
    }
    add_to_global((uint32_t) (strchr(line, '"') - line), line);
    line = strchr(line, '"') + 1;

    //for asciiz add trailing 0
    k = 0;
    if (cur_type == ASCIIZ) add_to_global(1, &k);

    return line;

}

char *read_number(char *line){
    if (*line == 0) {
        if (step == 2) perror_exit(1, "duplicated ,\n");
        step = 2;
        return NULL;
    }
    if (cur_type == BYTE || cur_type == HALF || cur_type == WORD){
        int k = 0;
        if (isnumber(line[0]))
            sscanf(line, "%i", &k);
        else if (line[0] == '\'')
            if (line[1] != '\\')
                k = line[1];
            else {
                for (int i = 0; i <= 20;i += 2){
                    if (line[2] == esc[i]){
                        k = esc[i + 1];
                        break;
                    }
                }

                if (k == 0 && isnumber(line[2]) && isnumber(line[3]) && isnumber(line[4])) {
                    k = (char) (((line[1] - '0') << 6) + ((line[2] - '0') << 3) + (line[3] - '0'));
                }

                if (k == 0 && line[1] == 'x' && isxdigit(line[2]) && isxdigit(line[3])){
                    //hex
                    k = (char) (((isdigit(line[2]) ? line[2] - '0' : isupper(line[2]) ? line[2] - 'A' + 10 : line[2] - 'a' + 10) << 4)
                         + (isdigit(line[3]) ? line[3] - '0' : isupper(line[3]) ? line[3] - 'A' + 10 : line[3] - 'a' + 10));
                }
            }
        else perrorf_exit(1, "failed to recognize integer: %s\n", line);
        add_to_global(cur_type == BYTE ? 1 : cur_type == HALF ? 2 : 4, &k);
    }

    if (cur_type == FLOAT){
        float f;
        sscanf(line, "%f", &f);
        add_to_global(4, &f);
    }

    if (cur_type == DOUBLE){
        double d;
        sscanf(line, "%lf", &d);
        add_to_global(8, &d);
    }

    return strchr(line, ',') == NULL ? NULL : strchr(line, ',');
}

void decode_data_line(char *line){
    if (data_read != 1) perrorf_exit(1, "ERROR\n");

    //start with number, "\".," are not new line
    if (!(isdigit(line[0]) || line[0] == '"' || line[0] == '.' || line[0] == ',')){
        //identifier
        if (step == 2 || strchr(line, ':') == NULL || line[0] == ':') perrorf_exit(1, "unexpected identifier: %s\n", line);
        memcpy(cur_name, line, strchr(line, ':') - line);
        if (*(strchr(line, ':') + 1) == 0) line = readline();
        else line = strchr(strchr(line, ':'), '.');
        if (line == NULL || *line != '.') perrorf_exit(1, "unexpected data type: %s\n", line != NULL ? line : "\b\b");

        //check type
        cur_type = 0;
        for (int i = 0; i < 8; i ++){
            if (startwith_incensitive(line, type_name[i])){
                cur_type = (uint32_t) (i + 8);
                line += strlen(type_name[i]);
                break;
            }
        }
        if (cur_type == 0) perrorf_exit(1, "unexpected data type: %s\n", line);

        hash_put(cur_name, (uint32_t) ((cur_type == SPACE) + 1), cur_type == SPACE ? uninitd : initd);
        line = skip_space(line);
        step = 2;
    }
    if (strlen(line) == 0) return;
    //data
    if (line[0] == ','){
        if (step == 1) {
            line = skip_space(line + 1);
            step = 2;
        }
        else if (step == 0) perrorf_exit(1, "unexpected data: %s\n", line);
        else  perror_exit(1, "duplicated comma\n");
    }
    if (step == 0) perrorf_exit(1, "unexpected data: %s\n", line);

    //string
    if (cur_type == ASCIIZ || cur_type == ASCII){
        while (line[0] == '"'){
            line = skip_space(read_string(line));
            step = 1;
        }
    } else if(cur_type == SPACE){
        int k;
        sscanf(line, "%i", &k);
        uninitd += k;
        step = 0;
    } else {
        //numbers
        while (strlen(line) != 0){
            char *k = read_number(line);
            step = 1;
            if (k == NULL) return;
            line = skip_space(strchr(k, ',') + 1);
        }
    }
}

void end_data(){
    if (data_read == 1)data_read = 2;
    if ((int32_t) (GLOBAL_MIN + initd + uninitd) > GLOBAL_MAX)
        perrorf_exit(1, "Too many global variable. \n");
}

void write_global(){
    //flush global area
    write_int32((int32_t) initd);

    write_segment(initd, global);

    write_int32((int32_t) uninitd);

    free(global);
}


int32_t data_get(char *name){
    if (data_read != 2) perror_exit(1, "ERROR\n");
    uint32_t loc = hash_get(name);
    if (last_type == 0 || loc == HASH_NOT_FOUND) return GLOBAL_NOT_FOUND;
    if (last_type == 1){
        //initialized
        return (int32_t) GLOBAL_MIN + loc;
    }
    if (last_type == 2){
        //initialized
        return (int32_t) GLOBAL_MIN + initd + loc;
    }
    return GLOBAL_NOT_FOUND;
}

void force_exit(){
    free(global);
}