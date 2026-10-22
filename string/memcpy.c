#include <stdio.h>
#include <string.h>

int main(){
        const char src[15] = "Hello World";
        char dest[15];
	strcpy(dest, "Helooooo!!");
 	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);
	return 0;	


}
