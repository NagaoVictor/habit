#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char * name;
} Prod;


int main(){
  Prod p;
  p.name = malloc(100);
  strcpy(p.name, "Raspberry Pi");
  
  printf("Prod: %s\n", p.name);

  free(p.name);

  return 0;
}
