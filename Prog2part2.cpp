/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that makes a box out of a given character
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int width = 0;
    int height = 0;
    string c = "a";

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter character: ";
    cin >> c;

    int i = 0;
    while (i < height){
        int j = 0;
        while (j < width){
            cout << c;
            j++;
        }
        cout << "\n";
        i++;
    }
}