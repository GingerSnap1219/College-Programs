/*
Jackson Hoornaert
CSCI 242
HW 2 Fibonacci
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

int fib_int(int N){
	int k1, k2, k3;
	k1 = k2 = k3 = 1;
	for(int j = 3; j <= N; j++){
		k3 = k1+ k3;
		k1 = k2;
		k2 = k3;
	}
	return k3;
}

int fib_rec(int n){
	if(n <= 1){
		return n;
	}else{
		return fib_rec(n-1) + fib_rec(n-2);
	}
}

int main(void){
	double t_start = 0;
	double t_end = 0;
	double t_total = 0;

	/*Interactive*/
	printf("Interactive Fibonacci \n");

	t_start = TIMER();

	for(int p = 0; p < 3; p++){
	printf("Enter the number of steps you want to go through: ");
	int s = 0;
	scanf("%i", &s);

	int s_total = fib_int(s);

	printf("Step %i = %i \n\n", s, s_total);
	}

	t_end = TIMER();
	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	/*Recursive*/
	printf("Recursive Fibonacci \n");

	t_start = TIMER();

	for(int q = 0; q < 3; q++){
	printf("Enter the number of steps you want to go through: ");
	int s2 = 0;
	scanf("%i", &s2);

	int s2_total = fib_rec(s2);
	printf("Step %i = %i \n\n", s2, s2_total);
	}

	t_end = TIMER();
	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	return 0;
}
