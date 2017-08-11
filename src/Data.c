//
// Created by Tyler on 2017/08/01.
//

#include "Data.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define global_min -8192
#define global_max 8191

bool data_read; //whether data region is read

void start_data(){
    if (data_read){
        fprintf(stderr, "Multiple Data region. Place check the assembly.\n");
        exit(1);
    }
    data_read = 1;
}

void decode_data_line(char *line){

}