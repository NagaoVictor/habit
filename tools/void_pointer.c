#include <stdio.h>
#include <stdlib.h>


int main(){
	void*ptr;
	int num = 10;
	ptr = &num;
	
	printf("Value of num: %d\n", *(int*)ptr);
	printf("Value of num: %d\n", *(int*)&num);
	return 0;

}




