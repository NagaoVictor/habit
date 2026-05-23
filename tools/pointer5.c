#include <stdio.h>


int sum(int *v, int n){
  int total = 0;

  for (int i = 0; i < n; i++){
    total += v[1];
  }
  return total;
}


int main(){
  int values[] = {1, 2, 3, 4, 5};
  
  printf("Sum = %d\n", sum(values, 5));

  return 0;
}
