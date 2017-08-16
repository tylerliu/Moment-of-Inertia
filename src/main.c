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
#include "FileIO.h"
#include "Text.h"
#include "FileIO.h"
#include "Hash.h"
#include "Data.h"

void parse(){
    //parse
    parse_data();
    parse_text();
    write_global();

    fseek(out, 0, SEEK_SET);
    fwrite(&bytes_written, 4, 1, out);
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
    write_int32(0);

    parse();

    fclose(in);
    fclose(out);
    hash_delete();
    return 0;
}
