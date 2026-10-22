#include <stdio.h>
#include <string.h>

int main(){
	char dest[20];
	char src[20];
	int len;

	strcpy(src, "Hello world");
	len = strxfrm(dest, src, 20);

	printf("Length of string |%s| is: |%d|\n", dest,len);
	return 0;

}
