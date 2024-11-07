/*
 * Jackson Hoornaert
 * jackson.hoornaert@und.edu
 * Part 4 - Convert given change into a dollar amount
 */

import java.util.Scanner;

public class Prog1part4 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        
        System.out.print("Quarters: ");
        int quarters = keyboard.nextInt();
        System.out.print("Dimes: ");
        int dimes = keyboard.nextInt();
        System.out.print("Nickels: ");
        int nickels = keyboard.nextInt();
        System.out.print("Pennies: ");
        int pennies = keyboard.nextInt();

        keyboard.close();

        double total = 0.00;
        total = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
        total /= 100;

        System.out.printf("Amount: $%.2f", total);
    }

}