/*
CSCI 330
HW6
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6-load.h"

struct _data *LOAD(FILE *stream, int size) {
    struct _data *BlackBox = malloc(size * sizeof(struct _data));
    if (!BlackBox) {
        perror("Memory allocation failed");
        exit(1);
    }

    char buffer[256];
    for (int i = 0; i < size; i++) {
        if (fgets(buffer, sizeof(buffer), stream)) {
            char *token = strtok(buffer, " \n");
            BlackBox[i].name = strdup(token);
            token = strtok(NULL, " \n");
            BlackBox[i].number = atol(token);
        }
    }
    return BlackBox;
}
