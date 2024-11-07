/*
Jackson Hoornaert
CSCI 242
HW 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	char person;
	int choices;
	char match;
	int i, j;

	for(i = 0; i < match; i++){
		match[i] = 0;
	}

	fp = foen("hw9.in", "r");
	if(fp == null{
		printf("Failed to open input file. \n");
		return 1;
	}

	for (i = 0; i < match; i++){
		if(fscanf(fp, " %c %d %d %d %d", &person, &choices[0], &choices[1], &choices[2], &choices[3]) != 5){
			printf("Error reading preferences. \n);
			fclose{fp};
			return 1;
		}
		for(j = 0; j < choices; j++){
			choices[j] = "A" + choices[j] - 1;
		}
		match[person - "1"] = choices[0];
	}

	for(i = 0; i < match; i++){
		int choice;
		if(fscanf(fp, " %d %c %c %c %c", &choice, &person, &person, &person, &person) != 5){
			printf("Error reading pairs. \n");
			fclose(fp);
			return 1;
		}
		match[person - "A"] = "1" + i;
	}

	for(i = 0; i < match; i++){
		printf("%c%d\n", "A" + i, match[i] - "0");
	}

	fclose(fp);

	return 0;
}
