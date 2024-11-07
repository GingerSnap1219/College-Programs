/*
CSCI 330
HW3
Jackson Hoornaert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data entries
typedef struct DataEntry{
    char name[50];
    float floatVal;
    int intVal;
    char color[50];
};

// Function to read data from file
struct DataEntry* readData(int* size) {
    FILE* file = fopen("hw4.data.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Dynamically allocate initial memory for Data array
    struct DataEntry* dataArray = malloc(sizeof(struct DataEntry));
    if (!dataArray) {
        fclose(file);
        perror("Failed to allocate memory");
        return NULL;
    }
    
    int count = 0;
    while (!feof(file)) {
        // Expand array as needed
        dataArray = realloc(dataArray, (count + 1) * sizeof(struct DataEntry));
        if (!dataArray) {
            fclose(file);
            perror("Failed to reallocate memory");
            return NULL;
        }
        
        if (fscanf(file, "%s %f %d %s", 
                   dataArray[count].name, 
                   &dataArray[count].floatVal, 
                   &dataArray[count].intVal, 
                   dataArray[count].color) == 4) {
            count++;
        }
    }
    fclose(file);
    *size = count; // Adjust size
    return dataArray;
}

//Sorting the structers by float
void sortByFloat(struct DataEntry entries[], int count){
    struct DataEntry temp;
    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(entries[j].floatVal > entries[i].floatVal){
                temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

//Sorting the structers by int
void sortByInt(struct DataEntry entries[], int count){
    struct DataEntry temp;
    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(entries[j].intVal > entries[i].intVal){
                temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}


//prints the data from high to low
void printHighToLow(struct DataEntry entries[], int count){
    for(int i = 0; i < count; i++){
        printf("%s %.1f %d, %s\n", entries[i].name, entries[i].floatVal, entries[i].intVal, entries[i].color);
    }
}

//Prints the data from low to high
void printLowToHigh(struct DataEntry entries[], int count){
    for(int i = count - 1; i >= 0; i--){
        printf("%s %.1f %d, %s\n", entries[i].name, entries[i].floatVal, entries[i].intVal, entries[i].color);
    }
}

int main(void){
int inLoop = 1;
    int choice = 0;
    int count = 0;
    int size = 0;
    struct DataEntry* entries = NULL;

    //count = readData(entries);

    //Menu
    while(inLoop == 1){
        printf("\nMenu: \n");
        printf("1. Sort data by the float value & print high to low\n");
        printf("2. Sort data by the float value & print low to high\n");
        printf("3. Sort data by the int value & print high to low\n");
        printf("4. Sort data by the int value & print low to high\n");
        printf("5. Exit\n");
        printf("ENTER YOUR OPTIONs: ");

        scanf("%d", &choice);
        printf("\n");

        if (choice >= 1 && choice <= 4) {
            // Read data from file
            entries = readData(&size);
            if (entries == NULL) {
                printf("Failed to read data.\n");
                continue;
            }
        }

        if(choice == 1){
            sortByFloat(entries, size);
            printHighToLow(entries, size);
        }else if(choice == 2){
            sortByFloat(entries, size);
            printLowToHigh(entries, size);
        }else if(choice == 3){
            sortByInt(entries, size);
            printHighToLow(entries, size);
        }else if(choice == 4){
            sortByInt(entries, size);
            printLowToHigh(entries, size);
        }else if(choice == 5){
            inLoop = 0;
        }else{
            printf("Your choice was not from the given options. Pick again.\n");
        }
    }
}