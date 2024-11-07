/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that counts from a given starting number to end number
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int start = 0;
    int end = 0;

    cout << "Enter starting value: ";
    cin >> start;
    cout << "Enter ending value: ";
    cin >> end;

        if (start <= end){
            for(int i = start; i < end + 1; i++){
                cout << i;
                cout << "\n";
            }
        }else{
            for (int i = start; i > end - 1; i--){
                cout << i;
                cout << "\n";
            }
        }
}