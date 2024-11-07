/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 1
Make a program that tracks the score and possible score of a set of students
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int score = 0;
    int posScore = 0;
    int numScores = 0;
    int totalPoints = 0;
    int totalPossible = 0;
    int perfScores = 0;
    string grade = "G";
    double avg = 0.00;

    while (score >= 0){
        cout << "Enter a score: ";
        cin >> score;
        if (score >= 0){
            numScores++;
            totalPoints += score;
        }else{
            break;
        }
        cout << "Enter the possible score: ";
        cin >> posScore;
        totalPossible += posScore;
        if (score == posScore){
            perfScores++;
        }
    }

    avg = ((double)totalPoints / (double)totalPossible) * 100;

    if (avg >= 90){
        grade = "A";
    }else if(avg > 80){
        grade = "B";
    }else if(avg > 70){
        grade = "C";
    }else if(avg > 60){
        grade = "D";
    }else{
        grade = "F";
    }

    cout << "\n";
    cout << "Number of scores: ";
    cout << numScores;
    cout << "\n";
    cout << "Total points: ";
    cout << totalPoints;
    cout << "\n";
    cout << "Total possible: ";
    cout << totalPossible;
    cout << "\n";
    cout << "Average: ";
    cout << fixed << setprecision(3);
    cout << avg;
    cout << "\n";
    cout << "Grade: ";
    cout << grade;
    cout << "\n";
    cout << "Perfect scores: ";
    cout << perfScores;
}