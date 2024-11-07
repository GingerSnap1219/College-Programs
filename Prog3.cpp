#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

extern "C" {
 int square(int intValue);
 int sumOfSquares(int intValue);
 bool isOdd(int intValue);
 bool isEven(int intValue);
 int compareTo(int intValue1, int intValue2);
 int maxMagnitude(int intValue1, int intValue2, int intValue3);
 int daysInFebruary(int year);
 char* militaryToRegularTime(int militaryTime);
}

int square(int intValue){
    return intValue * intValue;
}

int sumOfSquares(int intValue){
    int total = 0;
        for(int i = 1; i <= intValue; i++){
            total += square(i);
        }
        return total;
}

bool isOdd(int intValue){
    if(intValue % 2 != 0){
            return true;
        }else{
            return false;
        }
}

bool isEven(int intValue){
    if(intValue % 2 == 0){
            return true;
        }else{
            return false;
        }
}

int compareTo(int intValue1, int intValue2){
    if(intValue1 > intValue2){
            return 1;
        }else if(intValue2 > intValue1){
            return -1;
        }else{
            return 0;
        }
}

int maxMagnitude(int intValue1, int intValue2, int intValue3){
    if(abs(intValue1) > abs(intValue2)){
            if (abs(intValue1) > abs(intValue3)){
                return intValue1;
            }else{
                return intValue3;
            }
        }else if(abs(intValue2) > abs(intValue3)){
            return intValue2;
        }else{
            return intValue3;
        }
}

int daysInFebruary(int year){
    if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0){
                    return 29;
                }else{
                    return 28;
                }
            }else{
                return 29;
            }
        }else{
            return 28;
        }
}

char* militaryToRegularTime(int militaryTime){
    int hour = militaryTime / 100;
    int minutes = militaryTime % 100;
    string sHour = "1";
    string sMinutes = to_string(minutes);
    string timeOfDay = "G";



    if(hour >= 12){
        timeOfDay = "PM";
        if(hour == 12){
            sHour = "12";
        }
        hour -= 12;
        sHour = to_string(hour);
    }else if(hour < 12){
        timeOfDay = "AM";
        sHour = to_string(hour);
    }

    string test = sHour + ":" + sMinutes + " " + timeOfDay;
    
    int length = test.length();
    char* regArray = new char[length + 1];
    strcpy(regArray, test.c_str());

    return regArray;
}

int main(){
    cout << square(5);
    cout << "\n";
    cout << sumOfSquares(5);
    cout << "\n";
    cout << isOdd(5);
    cout << "\n";
    cout << isEven(3);
    cout << "\n";
    cout << compareTo(4,5);
    cout << "\n";
    cout << maxMagnitude(-23, 10, 52);
    cout << "\n";
    cout << daysInFebruary(2024);
    cout << "\n";
    cout << militaryToRegularTime(830);
}