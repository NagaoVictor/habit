#include <stdio.h>
#include <string.h>

//単語の長さを比較する
int main(){
	char str1[15];
	char str2[15];
	int ret;
	

	memcpy(str1, "Hello World", 12);
	memcpy(str2, "Hello World!", 13);

	ret = memcmp(str1, str2, 15);

	if (ret > 0){
		printf("str１はstr２より大きいです\n");	
	} else if (ret < 0){
		printf("str１はstr２より小さいです\n");
	} else {
		printf("str１はstr２と等しいです\n");
	}
	
	return 0;
		


}	
