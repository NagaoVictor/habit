#include <stdio.h>

void increment(int* p ){
  (*p)++;
}

int main(){
  int x = 5;
  increment(&x);
  
  printf("x = %d\n", x);

  return 0;
}


