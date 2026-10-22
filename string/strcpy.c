#include <stdio.h>
#include <string.h>

int main(){
	char src[15];
	char dest[25];

	memset(dest, '\0', sizeof(dest));
	strcpy(src, "Hello World");
	strcpy(dest, src);
	
	printf("Final copied string: %s\n", dest);

	return 0;
}	
