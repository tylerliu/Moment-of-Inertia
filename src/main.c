//
//
//
//
//
//Uses little Endian for instr.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fileIO.h"
#include "text.h"
#include "fileIO.h"
#include "Hash.h"
#include "Data.h"

void parse(){
    //parse
    parse_data();
    parse_text();
    write_text();
    write_global();
    //output
}

int main(int argc, char *argv[]) {

    //if (strstr(argv[1], ".gnfc") == NULL) printf("Incorrect file suffix. \n");

    hash_init();
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

    parse();

    fclose(in);
    fclose(out);
    hash_delete();
    return 0;
}
