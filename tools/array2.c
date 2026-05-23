#include <stdio.h>

int main(){
  int squares[10];
  
  for (int i = 0; i < 10; i++){
    squares[i] = i * i;
  }
  
  for (int i = 0; i < 10; i++){
    printf("%d ", squares[i]);
  }
  
  printf("\n");
  return 0;
}
