/*
Jackson Hoornaert
jackson.hoornaert@und.edu
Part 1 - Using user input create a mailing adress using 6 print statements
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string first = "";
    string last = "";
    string address = "";
    string city = "";
    string state = "";
    string zip = "";

    cout << "First: ";
    getline(cin, first);
    cout << "Last: ";
    getline(cin, last);
    cout << "Address: ";
    getline(cin, address);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin, state);
    cout << "Zip: ";
    getline(cin, zip);

    cout << first + " ";
    cout << last + "\n";
    cout << address + "\n";
    cout << city + ", ";
    cout << state + "  ";
    cout << zip;
}