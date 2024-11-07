/*
CSCI 330
HW6
Jackson Hoornaert
*/

#include <stdio.h>
#include <string.h>
#include "hw6-search.h"

void SEARCH(struct _data *BlackBox, char *name, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(BlackBox[i].name, name) == 0) {
            printf("*******************************************\n");
            printf("The name was found at the %d entry.\n", i + 1);
            printf("*******************************************\n");
            return;
        }
    }
    printf("*******************************************\n");
    printf("The name was NOT found.\n");
    printf("*******************************************\n");
}
