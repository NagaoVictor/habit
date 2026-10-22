#include <stdio.h>
#include <string.h>

int main(){
	int len;
	const char str1[] = "Tutorialspoint";
	const char str2[] = "Textbook";

	len = strcspn(str1, str2);

	printf("First matched character is at %d\n", len + 1);

	return 0;
}
