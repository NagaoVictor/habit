#include <stdio.h>
#include <string.h>

int main(){
	char src[20];
	char dest[50];

	memset(dest, '\0', sizeof(dest));
	strcpy(src, "Hello my friends");
	strncpy(dest,src,10);

	printf("Final copied string: %s\n", dest);

	return 0;

}
