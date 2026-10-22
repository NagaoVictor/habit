#include <stdio.h>
#include <string.h>

int main(){
	char str[15];
	strcpy(str, "Hello world");
	puts(str);

	memset(str, '#', 7);
	puts(str);
		
	return 0;

}
