#include <stdio.h>
#include <stdlib.h>


int main(){
	int x = 10;
	int y = 20;
	int z = 30;
	int *ptr = &x;
	int **dup_pointer = &ptr;
	*dup_pointer = &y;
	
	printf("%d\n", y);	
	*ptr = 25;
	printf("%d\n", y);	
	
	


}
