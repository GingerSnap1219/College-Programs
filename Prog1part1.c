/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 1 - Using user input create a mailing adress using 6 print statements
*/

#include <stdio.h>

int main(){
    char first[20] = "a";
    char last[20] = "a";
    char address[75] = "a";
    char city[20] = "a";
    char state[20] = "a";
    char zip[20] = "a";

    printf("First: ");
    scanf("%[^\n]%*c", first);
    printf("Last: ");
    scanf("%[^\n]%*c", last);
    printf("Address: ");
    scanf("%[^\n]%*c", address);
    printf("City: ");
    scanf("%[^\n]%*c", city);
    printf("State: ");
    scanf("%[^\n]%*c", state);
    printf("Zip: ");
    scanf("%[^\n]%*c", zip);
    printf("\n");

    printf("%s ", first);
    printf("%s\n", last);
    printf("%s\n", address);
    printf("%s, ", city);
    printf("%s  ", state);
    printf("%s", zip);
}