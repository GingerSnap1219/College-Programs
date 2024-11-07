/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that makes a box out of a given character
*/

import java.util.Scanner;

public class Prog2part2 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter width: ");
        int width = keyboard.nextInt();
        System.out.print("Enter height: ");
        int height = keyboard.nextInt();
        System.out.print("Enter character: ");
        String junk = keyboard.nextLine();
        String c = keyboard.nextLine();
        
        int i = 0;
        while (i < height){
            int j = 0;
            while (j < width){
                System.out.print(c);
                j++;
            }
            System.out.println();
            i++;
        }
        keyboard.close();
    }
}
