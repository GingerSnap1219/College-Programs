/*
CSCI 330
Quiz 4
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is exactly 3 (program name + 2 numbers)
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1; // Exit with an error code
    }

    // Convert arguments to float
    char *endptr1, *endptr2;
    double num1 = strtod(argv[1], &endptr1);
    double num2 = strtod(argv[2], &endptr2);

    // Check if the conversion was successful
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        printf("Error: Both arguments must be valid numbers.\n");
        return 1; // Exit with an error code
    }

    // Calculate the sum
    double sum = num1 + num2;

    // Print the result
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, sum);

    return 0; // Exit successfully
}
