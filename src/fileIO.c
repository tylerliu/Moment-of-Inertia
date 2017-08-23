//
// Created by Tyler on 2017/07/31.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "fileIO.h"
#include "text.h"
#include "Data.h"
#include "error.h"

char buf[1024];

void write_int32(uint32_t int32){
    fwrite(&int32, 4, 1, out);
}

void write_segment(uint32_t len, void * segment){
    fwrite(segment, 1, len, out);
}

char *readline(){
    char *ptr;
    if (fgets(buf, 1024, in) == NULL) return NULL;
    if (buf[strlen(buf) - 1] != '\n') perrorf_exit(1, "Line too long: %s...\n", buf);

    //delete comment
    if ((ptr = strstr(buf, "//")) != NULL) *ptr = '\0';
    if ((ptr = strchr(buf, ';')) != NULL) *ptr = '\0';


    //delete front spaces
    for (int i = 0;buf[i]; i++){
        if (buf[i] != ' ' && buf[i] != '\t'){
            if (i == 0) break;
            memmove(buf, buf + i, strlen(buf + i));
            buf[strlen(buf) - i] = 0;
            break;
        }
    }

    //delete trailing spaces
    for (int i = (int)strlen(buf) - 1;i >= 0; i --){
        if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n'){
            buf[i + 1] = 0;
            break;
        }
        if (i == 0){  //if this line contain white space only
            buf[i] = 0;
        }
    }

    return buf;
}

int parse_data(){
    if (!startwith_incensitive(buf, ".data")) {
        fseek(in, 0, SEEK_SET);//reset to head
        do {
            if (fgets(buf, 1024, in) == NULL){
                start_data();
                end_data();
                return 1;
            }
        } while (!startwith_incensitive(skip_space(buf), ".data"));
    }
    start_data();
    while (!(readline() == NULL || startwith_incensitive(buf, ".text"))) {
        decode_data_line(buf);
    }
    end_data();
    return 1;
}
int parse_text(){
    if (!startwith_incensitive(buf, ".text")) {
        fseek(in, 0, SEEK_SET);//reset to head
        do {
            if (fgets(buf, 1024, in) == NULL) perror_exit(1, "No text segment\n");
        } while (!startwith_incensitive(skip_space(buf), ".text"));
    }
    start_text();
    while (!(readline() == NULL || startwith_incensitive(buf, ".data"))) {
        decode_text_line(buf);
    }
    end_text();
    return 1;
}

int startwith(char *source, const char *pattern){
    return !memcmp(source, pattern, strlen(pattern));
}

int startwith_incensitive(char *source, const char *pattern){
    size_t len = strlen(pattern);
    for (int i = 0; i < len; i++){
        if (toupper(source[i]) != toupper(pattern[i])) return 0;
    }
    return 1;
}

char *skip_space(char *str){
    while (*str == ' ' || *str == '\t'){
        str++;
    }
    return str;
}