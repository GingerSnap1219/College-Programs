/*
CSCI 330
HW6
Jackson Hoornaert
*/

#include <stdlib.h>
#include "hw6-free.h"

void FREE(struct _data *BlackBox, int size) {
    for (int i = 0; i < size; i++) {
        free(BlackBox[i].name);
    }
    free(BlackBox);
}
