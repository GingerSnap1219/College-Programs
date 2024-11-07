/*Jackson Hoornaert
jackson.hoornaert@und.edu
Part 2
Make a program that makes a box out of a given character
*/

#include <stdio.h>

int main(){
    int width = 0;
    int height = 0;
    char c[2] = "";

    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter character: ");
    scanf("%s", c);

    int i = 0;
    while (i < height){
        int j = 0;
        while (j < width){
            printf("%s", c);
            j++;
        }
        printf("\n");
        i++;
    }
}