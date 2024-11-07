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

int readData(struct DataEntry entries[]){
    FILE *file = fopen("hw3.data.txt", "r");
    if (!file) { //lets the user know if the file failed to open
        perror("Failed to open file");
        exit(1);
    }

    int c = 0;
    while (c < 100 && fscanf(file, "%s %f %d %s", //counts how many entries there are
          entries[c].name, &entries[c].floatVal, 
          &entries[c].intVal, entries[c].color) == 4) {
        c++;
    }

    fclose(file);
    return c;
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
    struct DataEntry entries[100];

    count = readData(entries);

    //Menu
    while(inLoop == 1){
        printf("\nMenu: \n");
        printf("1. Sort data by the float value & print high to low\n");
        printf("2. Sort data by the float value & print low to high\n");
        printf("3. Sort data by the int value & print high to low\n");
        printf("4. Sort data by the int value & print low to high\n");
        printf("5. Exit\n");
        printf("Pick an option from the menu: ");

        scanf("%d", &choice);
        printf("\n");

        if(choice == 1){
            sortByFloat(entries, count);
            printHighToLow(entries, count);
        }else if(choice == 2){
            sortByFloat(entries, count);
            printLowToHigh(entries, count);
        }else if(choice == 3){
            sortByInt(entries, count);
            printHighToLow(entries, count);
        }else if(choice == 4){
            sortByInt(entries, count);
            printLowToHigh(entries, count);
        }else if(choice == 5){
            inLoop = 0;
        }else{
            printf("Your choice was not from the given options. Pick again.\n");
        }
    }
    return 0;
}

