//
// Created by Tyler on 2017/08/13.
//

#ifndef ERROR_H
#define ERROR_H

void error_exit(int error_num);

void perror_exit(int error_num, const char *message);

void perrorf_exit(int error_num, const char *format, ...);

#endif /* error.h */
