/*
 * Jackson Hoornaert
 * jackson.hoornaert@und.edu
 * Part 2 - Using user input create a mailing adress using 1 print statements
 */

import java.util.Scanner;

 public class Prog1part2{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        System.out.print("First: ");
        String first = keyboard.nextLine();
        System.out.print("Last: ");
        String last = keyboard.nextLine();
        System.out.print("Address: ");
        String address = keyboard.nextLine();
        System.out.print("City: ");
        String city = keyboard.nextLine();
        System.out.print("State: ");
        String state = keyboard.nextLine();
        System.out.print("Zip: ");
        String zip = keyboard.nextLine();
        System.out.println();

        keyboard.close();

        System.out.print(first + " " + last + "\n" + address + "\n" + city + ", " + state + "  " + zip);
    }
 }