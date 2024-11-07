/*
CSCI 330
HW6
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw6-scan.h"

int SCAN(FILE *stream) {
    int count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), stream)) {
        count++;
    }
    rewind(stream);
    return count;
}
