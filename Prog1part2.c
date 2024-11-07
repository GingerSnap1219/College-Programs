/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2 - Using user input create a mailing adress using 1 print statements
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

    printf("%s %s\n%s\n%s, %s  %s", first, last, address, city, state, zip);
}