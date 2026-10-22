#include <stdio.h>
#include <string.h>

int main(){
	char str_1[] = "gcc";
	char str_2[] = "g++";

	if (strncmp(str_1, str_2, strlen(str_2))==0){
		printf("The strings '%s' and '%s' are equal.\n", str_1, str_2);
	} else {
		printf("The strings '%s' and '%s' are not equal.\n", str_1, str_2);
	}
	return 0;

}
