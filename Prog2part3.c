/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that counts from a given starting number to end number
*/

#include <stdio.h>

int main(){
    int start = 0;
    int end = 0;

    printf("Enter starting value: ");
    scanf("%d", &start);
    printf("Enter ending value: ");
    scanf("%d", &end);

        if (start <= end){
            for(int i = start; i < end + 1; i++){
                printf("%d\n", i);
            }
        }else{
            for (int i = start; i > end - 1; i--){
                printf("%d\n", i);
            }
        }
}