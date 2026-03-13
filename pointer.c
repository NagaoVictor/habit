#include <stdio.h>
#include <stdlib.h>


int main(){
	int x = 10;
	int y = 20;
	int z = 30;
	int *ptr = &x;
	printf("Valor de x: %d\n", *ptr);
	*ptr = 20; //Alterar o valor apontado
	printf("Valor de x: %d\n", *ptr);
	ptr = &y; //Alterar o apontador
	
	printf("%d\n", y);
	*ptr = 25;
	printf("%d\n", y);
	
	
	


}
