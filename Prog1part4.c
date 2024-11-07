/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 4 - Convert given change into a dollar amount
*/

#include <stdio.h>

int main(){
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    float total = 0;

    printf("Part 4:\n\n");

    printf("Quarters: ");
    scanf("%d", &quarters);
    printf("Dimes: ");
    scanf("%d", &dimes);
    printf("Nickels: ");
    scanf("%d", &nickels);
    printf("Pennies: ");
    scanf("%d", &pennies);

    total = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
    total /= 100;

    printf("Ammount: $%.2f", total);
}