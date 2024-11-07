public class Prog4 {
    /*
    This function finds the max value in a list
    The parameters are an integer list
    It returns the max value in the list
    */
    int findMax(int[] intList){
        int max = -1;
        int temp = 0;

        for(int item: intList){
            temp = item;
            if(temp > 0){
                if(temp > max){
                    max = temp;
                }
            }
        }
        return max;
    }

    /*
    This function finds the min value in a list
    The parameters are an integer list
    It returns the min value in the list
    */
    int findMin(int[] intList){
        int min = 1000;
        int temp = 0;

        for(int item: intList){
            temp = item;
                if(temp < min){
                    min = temp;
                }
        }
        if(min != 1000){
            return min;
        }else{
            return -1;
        }
    }

    /*
    This function takes a list and makes sure each value is within the given bounds and if not sets it to those bounds depending on if it's over or under
    The parameters are a list and the lower and uper limit
    This does not return anything
    */
    void adjustList(int[] theList, int lowLimit, int highLimit){
        int x = 0;
        for(int item: theList){
            if(item < lowLimit){
                theList[x] = lowLimit;
            }
            if(item > highLimit){
                theList[x] = highLimit;
            }
            x++;
        }
        System.out.print(theList);
    }

    /*
    This calcuates the average of the values in the list
    The parameters are an integer list
    It returns the average as a float
    */
    static double calcAverage(int[] intList){
        double total = 0;
        double avg = 0;
        int x = 0;
        for(int item: intList){
            total += item;
            x++;
        }
        avg = total / x;
        return avg;
    }
    
    /*
    This function merges two given lists into one list
    The parameters are two int lists
    It returns the newly created list
    */
    int[] mergeLists(int[] list1, int[] list2){
        int[] newList = new int[list1.length + list2.length];
        int x = 0;
        for(int item1: list1){
            newList[x] = item1;
            x++;
        }
        for(int item2: list2){
            newList[x] = item2;
            x++;
        }
        return newList;
    }

    /*
    This function creates a new list of values within a given range of a given list
    The parameters are an int list along with a lower and uper limit
    It returns the newly created list
    */
    int[] valuesWithinRange(int[] theList, int lowLimit, int highLimit){
        int len = 0;
        for(int item: theList){
            if(item <= highLimit){
                if(item >= lowLimit){
                    len++;
                }
            }
        }

        int[] retList = new int[len];
        int x = 0;

        for(int item: theList){
            if(item <= highLimit){
                if(item >= lowLimit){
                    retList[x] = item;
                    x++;
                }
                
            }
        }
        return retList;
    }

    /*
    This funtion searches for a value in a given list
    The parameters are an int list and the value you want
    It returns the index of the fist time the value is found if it is in the list
    */
    int findInList(int[] theList, int valueToFind){
        int x = 0;
        for(int item: theList){
            if(item == valueToFind){
                return x;
            }
            x++;
        }
        return -1;
    }

    /*
    This funtion searches for a value in a given list
    The parameters are an int list and the value you want
    It returns the index of the fist time the value is found if it is in the list
    */
    int findInList(int[] theList, int valueToFind, int startingIndex){
        for(int i = startingIndex; i < theList.length; i++){
            if(theList[i] == valueToFind){
                return i;
            }
        }
        return -1;
    }

    int findInList(String[] theList, String valueToFind){
        int x = 0;
        for(String item: theList){
            if(item == valueToFind){
                return x;
            }
            x++;
        }
        return -1;
    }

    int findInList(String[] theList, String valueToFind, int startingIndex){
        for(int i = startingIndex; i < theList.length; i++){
            if(theList[i] == valueToFind){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[]args){
        int[] list1 = {6, 0, -1, 1, 5};

        System.out. print(calcAverage(list1));
    }
}
