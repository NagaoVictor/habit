#include <stdio.h>
#include <string.h>

int main(){
	const char str[20] = "TutorialsPoint";
	const char substr[10] = "Point";
	char *ret;

	ret = strstr(str, substr);

	printf("The substring is: %s\n", ret);

	return 0;


}
