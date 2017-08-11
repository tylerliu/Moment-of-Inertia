//
// Created by Tyler on 2017/07/31.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileIO.h"
#include "Text.h"
#include "Data.h"

#define TEXT 1
#define DATA 2

int seg_mode;

char buf[512];

void write_int32(uint32_t int32){
    fwrite(&int32, 4, 1, out);
}

char *readline(){
    char *ptr;
    if (fgets(buf, 512, in) == NULL) return NULL;

    //delete comment
    if ((ptr = strstr(buf, "//")) != NULL) *ptr = '\0';
    if ((ptr = strchr(buf, ';')) != NULL) *ptr = '\0';


    //delete front spaces
    for (int i = 0;buf[i]; i++){
        if (buf[i] != ' ' && buf[i] != '\t'){
            memmove(buf, buf + i, strlen(buf + i));
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

int categorize_parse(){
    if (readline() == NULL) return 0;
    if (buf[0] == 0) return READ_SUCCESS;
    if (strlen(buf) == 5 && buf[0] == '.') {

        char lower[5];
        for (int i = 0; i < 5; i++) lower[i] = (char) tolower(buf[i]);

        if (!memcmp(lower, ".text", 5)) {
            start_text();
            seg_mode = TEXT;
            return 1;
        }
        if (!memcmp(lower, ".data", 5)) {
            start_data();
            seg_mode = DATA;
            return 1;
        }
    }

    if (seg_mode == 0) {
        fprintf(stderr, "Fail to recognize region.\n");
        exit(0);
    }

    if (seg_mode == TEXT) decode_text_line(buf);
    if (seg_mode == DATA) decode_data_line(buf);
    return 1;
}