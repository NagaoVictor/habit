#include <stdio.h>

int add(int a){
  static int b = 0;
  b += a;
  return b;
}

int main(){
  int x = 10;
  printf("%d\n", add(x));
  x = 20;
  printf("%d\n", add(x));
}
