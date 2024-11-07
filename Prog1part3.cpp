/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 3 - Convert a number of milliseconds given by user input into minues, seconds, and leftover milliseconds
*/

#include <iostream>
using namespace std;

int main(){
    int ms = 0;
    int seconds = 0;
    int minutes = 0;

    cout << "Milliseconds: ";
    cin >> ms;

    seconds = ms / 1000;
    minutes = seconds / 60;
    seconds %= 60;
    ms %= 1000;

    cout << minutes;
    cout << "\n";
    cout << seconds;
    cout << "\n";
    cout << ms;
    cout << "\n";
}