#include <stdio.h>
#include <string.h>

int main(){
	const char str[] = "Hello.World";　//ベース文字列
	const char ch = '.'; // 初回のエラー
	char *ret;

	ret = memchr(str, ch, strlen(str));

	printf("String after |%c| is - |%s|\n", ch, ret);
	return(0);

}
