#include <iostream>
#include <string>
using namespace std;

    /*
    This function finds the max value in a list
    The parameters are an integer list
    It returns the max value in the list
    */
    int findMax(int size, int intList[]){
        int max = -1;
        int temp = 0;

        for(int i = 0; i < size; i++){
            temp = intList[i];
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
    int findMin(int size, int intList[]){
        int min = 1000;
        int temp = 0;

        for(int i = 0; i < size; i++){
            temp = intList[i];
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
    void adjustList(int size, int theList[], int lowLimit, int highLimit){
        int x = 0;
        for(int i = 0; i < size; i++){
            if(theList[i] < lowLimit){
                theList[x] = lowLimit;
            }
            if(theList[i] > highLimit){
                theList[x] = highLimit;
            }
            x++;
        }
    }

    /*
    This calcuates the average of the values in the list
    The parameters are an integer list
    It returns the average as a float
    */
    static double calcAverage(int size, int intList[]){
        double total = 0;
        double avg = 0;
        int x = 0;
        for(int i = 0; i < size; i++){
            total += intList[i];
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
    int* mergeLists(int size1, int list1[], int size2, int list2[]){
        int* newList = new int[size1 + size2];
        int x = 0;

        for(int i = 0; i < size1; i++){
            newList[x] = list1[i];
            x++;
        }
        for(int i = 0; i < size2; i++){
            newList[x] = list2[i];
            x++;
        }
        return newList;
    }

    /*
    This function creates a new list of values within a given range of a given list
    The parameters are an int list along with a lower and uper limit
    It returns the newly created list
    */
    int* valuesWithinRange(int size, int theList[], int lowLimit, int highLimit){
        int len = 0;
        for(int i = 0; i < size; i++){
            if(theList[i] <= highLimit){
                if(theList[i] >= lowLimit){
                    len++;
                }
            }
        }

        int* retList = new int[len];
        int x = 0;

        for(int i = 0; i < size; i++){
            if(theList[i] <= highLimit){
                if(theList[i] >= lowLimit){
                    retList[x] = theList[i];
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
    int findInList(int size, int theList[], int valueToFind){
        int x = 0;
        for(int i = 0; i < size; i++){
            if(theList[i] == valueToFind){
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
    int findInList(int size, int theList[], int valueToFind, int startingIndex){
        for(int i = startingIndex; i < size; i++){
            if(theList[i] == valueToFind){
                return i;
            }
        }
        return -1;
    }

    int findInList(int size, string theList[], string valueToFind){
        int x = 0;
        for(int i = 0; i < size; i++){
            if(theList[i] == valueToFind){
                return x;
            }
            x++;
        }
        return -1;
    }

    int findInList(int size, string theList[], string valueToFind, int startingIndex){
        for(int i = startingIndex; i < size; i++){
            if(theList[i] == valueToFind){
                return i;
            }
        }
        return -1;
    }

    #ifndef COMPILE_MAIN
    main(){
        int list1[] = {6, 0, -1, 1, 5};

        cout << calcAverage(5, list1);

        return 0;
    }
    #endif