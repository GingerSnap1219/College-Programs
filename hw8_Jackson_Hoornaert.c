/*
Jackson Hoornaert
CSCI 242
HW 2
*/

#include <stdio.h>
#include <sys/time.h>

double TIMER(void){
	struct timeval tp;
	struct timezone tzp;
	int i;

	i = gettimeofday(&tp,&tzp);
	return((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}

int fib(int n){
	if(n <= 1){
		return n;
	}else{
		return fib(n-1) + fib(n-2);
	}
}

int fibBU(int n){
	int fib2[100];
	fib2[0] = 0;
	fib2[1] = 1;
	for(int i = 1; i <= n; i++){
		fib2[i] = fib2[n-1] + fib2[n-2];
	}
	return fib2[n];
}

int map[100];
int fibTD(int n){
	if(map[n] != -1){
		return map[n];
	}
	map[n] = fibTD(n-1) + fibTD(n-2);
	return map[n];
}

int main(){
	int f = 10;
	double t_start, t_end, t_total;

	t_start = TIMER();
	for(int i = 0; i < 1000; i++){
		fib(f);
	}
	t_end = TIMER();
	t_total = t_end - t_start;

	printf("Recursive time: %f \n", t_total);

	t_start = TIMER();
	for(int i = 0; i < 1000; i++){
		fibBU(f);
	}
	t_end = TIMER();
	t_total = t_end - t_start;

	printf("Bottome-up time: %f \n", t_total);

	t_start = TIMER();
	for(int i = 0; i < 1000; i++){
		map[0] = 0;
		map[1] = 1;
		fibTD(f);
	}
	t_end = TIMER();
	t_total = t_end - t_start;

	printf("Top-down time: %f \n", t_total);

	return 0;
}
