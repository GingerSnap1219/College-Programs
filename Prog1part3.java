/*
 * Jackson Hoornaert
 * jackson.hoornaert@und.edu
 * Part 3 - Convert a number of milliseconds given by user input into minues, seconds, and leftover milliseconds
 */

import java.util.Scanner;

public class Prog1part3 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Milliseconds: ");
        int ms = keyboard.nextInt();

        keyboard.close();

        int seconds = ms / 1000;
        int minutes = seconds / 60;
        seconds %= 60;
        ms %= 1000;

        System.out.println(minutes);
        System.out.println(seconds);
        System.out.println(ms);
    }
}
