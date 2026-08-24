#include <stdio.h>

int main(int argc, char * argv[]){
  printf("O nome desse programa e '%s'.\n", argv[0]);
  printf("Esse programa foi chamado com %d argumentos.\n", argc-1);
  
  if (argc > 1){
    int i;
    printf("Os argumentos sao:\n");
    for (i = 1; i < argc; ++i){
      printf(" %s\n", argv[i]);
    }
  }
  return 0;

}
