#include <stdio.h>

int main(){
  int values[5] = {10, 20, 30, 40 ,50};

  for (int i = 0; i < 5; i ++){
    printf("Values[%d] = %d\n", i, values[i]);
  }
  return 0;

}
