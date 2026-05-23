#include <stdio.h>


int main(){
  int v[] = {10, 20, 30 ,40};
  int *p = v;

  for (int i = 0; i < 4; i++){
    printf("%d\n", *(p+i));
  }

  return 0;
}
