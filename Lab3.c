// George Juarez - Lab #3
/*
  The value of the mathematical constant e can be expressed as an infinite series:
	e = 1 + 1/1!  + 1/2! + 1/3! + ... 1/n!
	Write a program that approximates e by computing this value
	where n is an integer entered by the user.
	The user must enter an integer between 0 and 15. If not, end the program. Do not
	use any function from math.h
*/

#include <stdio.h>
#include <stdlib.h>

float findE(int);

int main(void) {
	float inputNum, res;
	printf("Enter a number between 0 and 15: ");
	scanf("%f", &inputNum);
	if (inputNum < 0 || inputNum > 15) {
		printf("\nPlease enter a number between 0 and 15. Try again. \n");
		exit(0);
	}
	else {
		res = findE(inputNum);
		printf("\nYour sum is: %f .\n",res);

	}
	return 0;
}

float findE(int num) {
	int i;
	float sum = 0;
	for(i = 1; i < num; i++){
		sum += 1.0/(findE(i));
	}
	return sum;
}
