#include <stdio.h>
#include <stdlib.h>
#include "access.h" //Access

int main(){
	Grade grade;
	printf("A scale from ZERO to TEN: ");
	scanf("%d", &grade);
	if (grade<0 || grade>10){
		printf("Enter with valid number\n");
		return 1;

	}
	printf("Scale 1 to 10 is: %d\n", grade);
	

}
