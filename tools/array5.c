#include <stdio.h>

int main(){
  int values[] = {10, 20, 30, 40, 50};
  int target = 30;
  int n = sizeof(values) / sizeof(values[0]);
  int found = -1;

  for (int i = 0; i < n; i++){
    if (values[i] == target){
      found = i;
      break;
    }
  }

  printf("Indice = %d\n", found);
  
  return 0;
}
