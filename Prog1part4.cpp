/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 4 - Convert given change into a dollar amount
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    double total = 0.00;

    cout << "Quarters: ";
    cin >> quarters;
    cout << "Dimes: ";
    cin >> dimes;
    cout << "Nickels: ";
    cin >> nickels;
    cout << "Pennies: ";
    cin >> pennies;

    total = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
    total /= 100;

    cout << "Amount: ";
    cout << fixed << setprecision(2);
    cout << total;
}