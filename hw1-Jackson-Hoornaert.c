/*
CSCI 242
HW1
Jackson Hoornaert
*/

#include <stdio.h>

int main(void){
	double b = 5000.0;
	double r = 0.22;

	printf("Enter your monthly payment: ");
	double p = 0;
	scanf("%lf", &p);

	printf("r = %.2f \n", r);
	printf("B = %.2f \n", b);
	printf("P = %.2f \n\n", p);

	int x;
	double i;
	double rB = b;
	double tI;

	for (x = 1; x <= 12; x++){
		i = (r/12) * rB;

		
		printf("%i. %.2f %.2f\n", x, i, rB);
		rB -= p;
		rB += i;
		tI += i;
	}

	printf("Total interest paid: %.2f\n", tI);

	return 0;
}
