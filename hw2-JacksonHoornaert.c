/*
CSCI 330
HW2
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "students.txt"
#define OUTPUT_FILE "processed_students.txt"

char get_letter_grade(float average);
void process_students(FILE *input_file, FILE *output_file);

int main() {
    FILE *input_file = fopen(INPUT_FILE, "r");
    FILE *output_file = fopen(OUTPUT_FILE, "w");

    // Check if input file can be opened
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Check if output file can be opened
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Process the students and write the output
    process_students(input_file, output_file);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}

// Function to determine the letter grade from the average
char get_letter_grade(float average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

// Function to process student data and write results to the output file
void process_students(FILE *input_file, FILE *output_file) {
    int id, grade1, grade2, grade3;
    char name[50];
    int count = 0;

    // Read the student data from the input file
    while (fscanf(input_file, "%d %49s %d %d %d", &id, name, &grade1, &grade2, &grade3) == 5) {
        float average = (grade1 + grade2 + grade3) / 3.0;
        char letter_grade = get_letter_grade(average);

        // Write the processed data to the output file
        fprintf(output_file, "%d %s %.2f %c\n", id, name, average, letter_grade);
        count++;
    }

    // Display an error message if the input file is empty
    if (count == 0) {
        fprintf(stderr, "Error: The input file is empty or contains invalid data.\n");
    }
}
