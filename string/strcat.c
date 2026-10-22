#include <stdio.h>
#include <string.h>

int main(){
	char dest_str[20] = "C ";
	const char src_str[] = "JAVA";

	strcat(dest_str, src_str);

	printf("%s\n", dest_str);
	return 0;

}
