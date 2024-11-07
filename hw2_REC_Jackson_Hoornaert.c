/*
Jackson Hoornaert
CSCI 242
HW 2 Factorial
*/

#include <stdio.h>
#include <sys/time.h>

double TIMER(void){
	struct timeval tp;
	struct timezone tzp;
	int i;

	i = gettimeofday(&tp, &tzp);
	return((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}

int factorial_int(int n){
	int i, result = 1;
	for(i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}

int factorial_rec(int n){
	if(n <= 1){
		return 1;
	}else{
		return n * factorial_rec(n-1);
	}
}

int main(void){
	double t_start, t_end, t_total;
	t_start = t_end = t_total = 0;

	/*Interactive*/
	printf("Interactive Factorial \n");

	t_start = TIMER();

	for(int p = 0; p < 3; p++){
	printf("Enter the number you want to factorial: ");
	int n = 0;
	scanf("%i", &n);

	int total = factorial_int(n);
	printf("%i factorial is %i \n\n", n, total);
	}

	t_end = TIMER();
	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	/*Recursive*/
	printf("Recursive Factorial \n");

	t_start = TIMER();

	for(int q = 0; q < 3; q++){
	printf("Enter the number you want to factorial: ");
	int n2 = 0;
	scanf("%i", &n2);

	int total2 = factorial_rec(n2);
	printf("%i factorial is %i \n\n", n2, total2);
	}

	t_end = TIMER();
	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	return 0;
}
