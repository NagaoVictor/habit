#include <stdio.h>

int main(){
  int x =10;
int *p = &x;

  *p = 99;

  printf("x = %d\n", x);

  return 0;
}


