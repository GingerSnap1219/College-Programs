/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 1
Make a program that tracks the score and possible score of a set of students
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int score = 0;
    int posScore = 0;
    int numScores = 0;
    int totalPoints = 0;
    int totalPossible = 0;
    int perfScores = 0;
    char grade = 'G';
    double avg = 0.00;

    while (score >= 0){
        printf("Enter a score: ");
        scanf("%d", &score);
        if (score >= 0){
            numScores++;
            totalPoints += score;
        }else{
            break;
        }
        printf("Enter the possible score: ");
        scanf("%d", &posScore);
        totalPossible += posScore;
        if (score == posScore){
            perfScores++;
        }
    }

    avg = ((double)totalPoints / (double)totalPossible) * 100;

    if (avg >= 90){
        grade = 'A';
    }else if(avg > 80){
        grade = 'B';
    }else if(avg > 70){
        grade = 'C';
    }else if(avg > 60){
        grade = 'D';
    }else{
        grade = 'F';
    }

    printf("\nNumber of scores: %d", numScores);
    printf("\nTotal points: %d", totalPoints);
    printf("\nTotal possible: %d", totalPossible);
    printf("\nAverage: %.3f", avg);
    printf("\nGrade: %c", grade);
    printf("\nPerfect scores: %d", perfScores);
}