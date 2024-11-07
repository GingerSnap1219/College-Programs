/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 3 - Convert a number of milliseconds given by user input into minues, seconds, and leftover milliseconds
*/

#include <stdio.h>

int main(){
    int ms = 0;

    printf("Milliseconds: ");
    scanf("%d", &ms);

    int seconds = ms / 1000;
    int minutes = seconds / 60;
    seconds %= 60;
    ms %= 1000;
    
    printf("%d", minutes);
    printf("\n");
    printf("%d", seconds);
    printf("\n");
    printf("%d", ms);
}