//
// Created by Tyler on 2017/08/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Hash.h"
#include "FileIO.h"
#include "Data.h"

extern void *global;

void error_exit(int error_num){

    fclose(in);
    fclose(out);
    hash_delete();
    force_exit();
    exit(error_num);
}

void perror_exit(int error_num, const char *message){
    fprintf(stderr, "%s", message);
    error_exit(error_num);
}


int perrorf_exit(int error_num, const char *format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
    error_exit(error_num);
}