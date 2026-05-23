#include <stdio.h>

int main(){
  int values[] = {8, 12, 3, 99, 17};
  int n = sizeof(values) / sizeof(values[0]);
  int max = values[0];
  
  for (int i = 1; i < n; i++){
    if (values[i] > max){
      max = values[i];
    }

  }
  
  printf("Maximum values = %d\n", max);
  return 0;

}
