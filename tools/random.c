#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	// Time seed.
	srand(time(NULL));
	// 0 to 10
	int s = rand()%10;
	// 0 to 11;
	int d = rand()%11;
	printf("%d %d\n", s, d);
	return 0;

}
