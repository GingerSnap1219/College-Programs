/*
 * Jackson Hoornaert
 * jackson.hoornaert@und.edu
 * Part 1 - Using user input create a mailing adress using 6 print statements
 */
import java.util.Scanner;

 public class Prog1part1{
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

        System.out.print(first + " ");
        System.out.println(last);
        System.out.println(address);
        System.out.print(city + ", ");
        System.out.print(state + "  ");
        System.out.print(zip);
    }
 }