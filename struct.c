#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sup1;
	int sup2;
	int sup3;

}Test;


int main(){
	Test Static = {.sup1=20, .sup2=40, .sup3=15};// Usando o espaco da Test Struct
	Test * Dynamic;//Criando um espaco
	Dynamic = (Test*)malloc(sizeof(Test));
	Dynamic->sup1=21;
	Dynamic->sup2=41;
	Dynamic->sup3=16;
	printf("%d %d %d\n", Static.sup1, Static.sup2, Static.sup3);		
	printf("%d %d %d\n", Dynamic->sup1, Dynamic->sup2, Dynamic->sup3);
	Dynamic->sup1=22;
	Dynamic->sup2=42;
	Dynamic->sup3=17;
	printf("%d %d %d\n", Dynamic->sup1, Dynamic->sup2, Dynamic->sup3);
	
}
