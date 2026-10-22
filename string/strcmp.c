#include <stdio.h>
#include <string.h>

int main(){
	char str1[] = "Victor", str2[] = "victor!";
	int res;

	res = strcmp(str1, str2);
	printf("strcmp(str1, str2) = %d\n", res);
	return 0;



}
