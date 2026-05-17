#include <stdio.h>

#define SIZE 5

int main(){
  int buffer[SIZE] = {0};
  int head = 0;
  
  for (int i = 1; i <= 10; i++){
    buffer[head] = i;
    head = (head + 1) % SIZE;
  }

  for (int i = 0; i < SIZE; i++){
    printf("%d ", buffer[i]);
  }
  printf("\n");
  return 0;

}
