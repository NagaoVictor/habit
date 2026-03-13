#include <stdio.h>
#include <stdlib.h>

// Abstract method
// Assign
int add(int num1, int num2);
int sub(int num1, int num2);

int main(){
	int (*ope[2])(int, int);
	ope[0] = add;
	ope[1] = sub;
	printf("Sum: %d, Sub: %d\n", add(10,20), sub(20, 10));

}

// Set
int add(int num1, int num2){return (num1+num2);}
int sub(int num1, int num2){return (num1-num2);}
