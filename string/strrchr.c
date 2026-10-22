#include <stdio.h>
#include <string.h>

int main(){
	int len;
	const char str[] = "The best place in the world";
	const char ch = ' ';
	char *ret;

	ret =  strrchr(str, ch);
	
	printf("String after |%c| is - |%s|\n", ch, ret);	
	return 0;

}
