/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that counts from a given starting number to end number
*/

import java.util.Scanner;

public class Prog2part3 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter starting value: ");
        int start = keyboard.nextInt();
        System.out.print("Enter ending value: ");
        int end = keyboard.nextInt();

        if (start <= end){
            for(int i = start; i < end + 1; i++){
                System.out.println(i);
            }
        }else{
            for (int i = start; i > end - 1; i--){
                System.out.println(i);
            }
        }
        keyboard.close();
    }
}
