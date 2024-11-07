/*
CSCI 330
HW6
Jackson Hoornaert
*/

#ifndef HW6_LOAD_H
#define HW6_LOAD_H

#include <stdio.h>

struct _data {
    char *name;
    long number;
};

struct _data *LOAD(FILE *stream, int size);

#endif // HW6_LOAD_H
