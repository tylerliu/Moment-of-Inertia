//
// Created by Tyler on 2017/08/22.
//


#include <stdint.h>
#include <stdlib.h>
#include "../Hash.h"
#include "../text.h"
#include "../error.h"
#include "label.h"
#include "text_instr.h"

typedef struct{
    uint32_t loc;
    uint32_t next;
} jump_ref;

uint32_t ref_len = 128;
uint32_t ref_used = 1;
jump_ref *ref_area;

void label_init(){
    ref_area = malloc(ref_len * sizeof(jump_ref));
}

void new_label(char *name){
    uint32_t loc = hash_get(name);
    if (loc == HASH_NOT_FOUND){
        hash_put(name, 0, get_text_loc());
        return;
    }
    if (last_type != HASH_TYPE_REF) {
        perrorf_exit(1, "duplicated symbol: %s\n", name);
    }
    //last type == 1
    while (loc != 0) {
        uint32_t instr = get_instr(ref_area[loc].loc);
        //printf("%d\n", get_text_loc() - (ref_area[loc].loc + 1));
        if (((Instr_format_S *)&instr) ->imm == 1)
            fill_imm_S((Instr_format_S *)&instr, get_text_loc() - (ref_area[loc].loc + 1));
        else fill_imm_UJ((Instr_format_U *)&instr, get_text_loc() - (ref_area[loc].loc + 1));
        set_instr(ref_area[loc].loc, instr);
        loc = ref_area[loc].next;
    }
    hash_change(name, HASH_TYPE_TEXT, get_text_loc());
}

uint32_t ref_label(char *name){
    uint32_t loc = hash_get(name);
    if (loc != HASH_NOT_FOUND && last_type == HASH_TYPE_TEXT) {
        //printf("%d\n", loc - (get_text_loc() + 1));
        return loc - (get_text_loc() + 1);
    }

    //new ref
    if (ref_len == ref_used){
        ref_len <<= 1;
        ref_area = realloc(ref_area, ref_len * sizeof(jump_ref));
    }
    ref_area[ref_used].loc = get_text_loc();
    ref_area[ref_used].next = loc == HASH_NOT_FOUND ? 0 : loc;
    if (loc == HASH_NOT_FOUND) hash_put(name, 1, ref_used);
        else hash_change(name, 1, ref_used);
    ref_used ++;

    return LABEL_FILL_TEMP;
}

void label_end(){
    free(ref_area);
}

void label_force_exit(){
    free(ref_area);
}