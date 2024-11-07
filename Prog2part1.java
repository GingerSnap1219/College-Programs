/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 1
Make a program that tracks the score and possible score of a set of students
*/

import java.util.Scanner;

public class Prog2part1 {
    public static void main(String[] args){
        int score = 0;
        int posScore = 0;
        int numScores = 0;
        int totalPoints = 0;
        int totalPossible = 0;
        int perfScores = 0;
        String grade = "G";
        double avg = 0.00;

        Scanner keyboard = new Scanner(System.in);

        while (score >= 0){
            System.out.print("Enter a score: ");
            score = keyboard.nextInt();
            if (score >= 0){
                numScores++;
                totalPoints += score;
            }else{
                break;
            }
            System.out.print("Enter the possible score: ");
            posScore = keyboard.nextInt();
            totalPossible += posScore;
            if (score == posScore){
                perfScores++;
            }
        }

        avg = ((double)totalPoints / totalPossible) * 100;

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

        System.out.println();
        System.out.println("Number of scores: " + numScores);
        System.out.println("Total points: " + totalPoints);
        System.out.println("Total possible: " + totalPossible);
        System.out.printf("Average: %.3f\n", avg);
        System.out.println("Grade: " + grade);
        System.out.println("Perfect scores: " + perfScores);

        keyboard.close();
    }
}
