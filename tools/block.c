#include <stdio.h>



int main(){
  int a;
  a = 20;
  printf("%d\n", a);
  printf("%p\n", &a);
  {a = 10;
    printf("%d\n", a);
    printf("%p\n", &a);  
  }
  printf("%d\n", a);

}
