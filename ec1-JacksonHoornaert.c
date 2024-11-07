/*
CSCI 330
Jackson Hooranert
Extra Credit 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int staticAges[4];
    int *ages = (int*) malloc(4 * sizeof(int));
    
    if (ages == NULL) {
        printf("Error: allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        staticAges[i] = 10 + i;
        printf("%d\n", staticAges[i]);
    }

    for (int i = 0; i < 4; i++) {
        ages[i] = 1 + i;
        printf("%d\n", ages[i]);
    }

    // Handle realloc safely
    int *temp = (int *)realloc(ages, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Error: reallocation failed\n");
        free(ages); // Free the original memory
        return 1;   // Exit since we cannot proceed without valid memory
    }
    ages = temp; // Assign the new pointer if realloc is successful

    // Optionally, initialize the new elements
    for (int i = 4; i < 6; i++) {
        ages[i] = 2 + i; // For example, assign new values
    }

    // Print the updated ages
    for (int i = 0; i < 6; i++) {
        printf("%d\n", ages[i]);
    }

    free(ages); // Don't forget to free the allocated memory
    return 0;
}
