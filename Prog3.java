//Jackson Hoornaert
//jackson.hoornaert@und.edu

import java.lang.Math;

public class Prog3 {
    //This function takes in an integer and squares it and then returns that value
    public static int square (int intVal){
        return intVal * intVal;
    }

    //This function take in an integer and adds to squares between
    //1 and the given value and returns the sum
    public static int sumOfSquares (int intVal){
        int total = 0;
        for(int i = 1; i <= intVal; i++){
            total += square(i);
        }
        return total;
    }

    //This function takes and integer and determines if it's odd
    //and returns True if it is and False if not
    public static boolean isOdd (int intVal){
        if(intVal % 2 != 0){
            return true;
        }else{
            return false;
        }
    }

    //This function takes and integer and determines if it's even
    //and returns True if it is and False if not
    public static boolean isEven (int intVal){
        if(intVal % 2 == 0){
            return true;
        }else{
            return false;
        }
    }

    //This function takes in two integers and compares them if int1
    //is greater it returns 1 if int2 is greater it returns -1 and 
    //if they are even it returns 0
    public static int compareTo (int intVal1, int intVal2){
        if(intVal1 > intVal2){
            return 1;
        }else if(intVal2 > intVal1){
            return -1;
        }else{
            return 0;
        }
    }

    //This function takes in 3 integers and returns the one with the greatest absolute value
    public static int maxMagnitude (int intVal1, int intVal2, int intVal3){
        if(Math.abs(intVal1) > Math.abs(intVal2)){
            if (Math.abs(intVal1) > Math.abs(intVal3)){
                return intVal1;
            }else{
                return intVal3;
            }
        }else if(Math.abs(intVal2) > Math.abs(intVal3)){
            return intVal2;
        }else{
            return intVal3;
        }
    }

    //This funtion takes in an integer year and tells you how many days February has
    public static int daysInFebruary (int year){
        if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0){
                    return 29;
                }else{
                    return 28;
                }
            }else{
                return 29;
            }
        }else{
            return 28;
        }
    }

    //This function takes in an integer military time and returns the regular time
    public static String militaryToRegularTime(int militaryTime){
        String mT = Integer.toString(militaryTime);
        String hour = "a";
        String minutes = "a";
        String timeOfDay = "G";

        if(mT.length() == 4){
            hour = mT.substring(0,2);
            minutes = mT.substring(2);
        }else if(mT.length() == 3){
            hour = mT.substring(0,1);
            minutes = mT.substring(1);
        }else{
            hour = "12";
            minutes = "00";
        }

        if(militaryTime - 12 >= 0){
            if(Integer.valueOf(hour) - 12 == 0){
                hour = "12";
            }else{
                hour = Integer.toString(Integer.valueOf(hour) - 12);
            }
            timeOfDay = "PM";
        }else{
            timeOfDay = "AM";
        }
        return hour + ":" + minutes + " " + timeOfDay;
    }

    public static void main(String[] args){
        System.out.println(square(5));
        System.out.println(sumOfSquares(5));
        System.out.println(isOdd(5));
        System.out.println(isEven(3));
        System.out.println(compareTo(4,5));
        System.out.println(maxMagnitude(32, -12, -24));
        System.out.println(daysInFebruary(2024));
        System.out.println(militaryToRegularTime(0));
    }
}
