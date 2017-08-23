//
// Created by Tyler on 2017/08/22.
//

#ifndef LABEL_H
#define LABEL_H

#define LABEL_FILL_TEMP 0

void label_init();
void new_label(char *name);
uint32_t ref_label(char *name);
void label_end();
void label_force_exit();

#endif /* label.h */
