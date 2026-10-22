#include <stdio.h>
#include <string.h>

int main(){
	const char * str = "Hello world";
	char ch = ' ';
	char *p = strchr(str,ch);

	if (p != NULL){
		printf("String starting from '%c' is: %s\n", ch, p);
	} else {
		printf("Character '%c' not found in the string.\n", ch);
	}

	return 0;

}
