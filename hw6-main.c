/*
CSCI 330
HW6
Jackson Hoornaert
*/

#include <stdio.h>
#include "hw6-main.h"
#include <windows.h>

// Add this function in your main.c file
void print_current_directory() {
    char cwd[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, cwd)) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("GetCurrentDirectoryA() error");
    }
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("*******************************************\n");
        printf("* You must include a name to search for. *\n");
        printf("*******************************************\n");
        return 1;
    }



print_current_directory();


    FILE *file = fopen("hw6.data.txt", "r");
    if (!file) {
        perror("Failed to open the file");
        return 1;
    }

    int size = SCAN(file);
    if (size <= 0) {
        printf("No entries found in the file.\n");
        fclose(file);
        return 1;
    }

    struct _data *BlackBox = LOAD(file, size);
    fclose(file);
    SEARCH(BlackBox, argv[1], size);
    FREE(BlackBox, size);
    return 0;
}
