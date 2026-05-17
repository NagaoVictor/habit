#include <stdio.h>
#include <stdlib.h>


int main(){
  int *p = malloc(sizeof(int));
  if (p==NULL){
    return 1;
  }
  *p = 123;
  
  printf("%d\n", *p);
  
  free(p);
  
  return 0;
}



