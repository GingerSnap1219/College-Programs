/*
CSCI 330
HW5
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data entries
struct _data{
    char *name;
    long number;
};

// Function to scan the file and count the lines
int SCAN(FILE **stream) {
    int count = 0;
    char buffer[256];

    // Read through the file to count lines
    while (fgets(buffer, sizeof(buffer), *stream)) {
        count++;
    }

    // Rewind the file for reading
    rewind(*stream);
    return count;
}

// Function to load the data from the file into a dynamic array
struct _data *LOAD(FILE *stream, int size) {
    struct _data *BlackBox = malloc(size * sizeof(struct _data));
    if (!BlackBox) {
        perror("Memory allocation failed");
        exit(1);
    }

    char buffer[256];
    for (int i = 0; i < size; i++) {
        if (fgets(buffer, sizeof(buffer), stream)) {
            // Tokenize the input to extract name and number
            char *token = strtok(buffer, " \n");
            BlackBox[i].name = strdup(token); // Allocate memory for name
            token = strtok(NULL, " \n");
            BlackBox[i].number = atol(token); // Convert string to long
        }
    }
    return BlackBox;
}

// Function to search for a name in the data array
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

// Function to free allocated memory
void FREE(struct _data *BlackBox, int size) {
    for (int i = 0; i < size; i++) {
        free(BlackBox[i].name); // Free each name
    }
    free(BlackBox); // Free the array of structs
}

int main(int argc, char **argv) { // Correct parameter names
    // Check for command line argument
    if (argc < 2) {
        printf("*******************************************\n");
        printf("* You must include a name to search for. *\n");
        printf("*******************************************\n");
        return 1; // Exit with error code
    }

    // Open the data file
    FILE *file = fopen("hw5.data", "r");
    if (!file) {
        perror("Failed to open the file");
        return 1; // Exit with error code
    }

    // Scan the file to count the lines
    int size = SCAN(&file);
    if (size <= 0) {
        printf("No entries found in the file.\n");
        fclose(file);
        return 1; // Exit with error code
    }

    // Load the data into the struct array
    struct _data *BlackBox = LOAD(file, size);
    fclose(file); // Close the file after loading

    // Search for the provided name
    SEARCH(BlackBox, argv[1], size);

    // Free allocated memory
    FREE(BlackBox, size);

    return 0; // Successful completion
}