#include <stdio.h>
#include <stdlib.h>

int main(){
  int n = 5;
  int * buffer = malloc(n * sizeof(int));
  
  if (buffer == NULL){
    return 1;
  }  
  
  for (int i = 0; i < n; i++){
    buffer[i] = i * 10;
  }
  
  for (int i = 0; i < n; i++){
    printf("%d\n", buffer[i]);
  }

  free(buffer);
  
  return 0;


}
