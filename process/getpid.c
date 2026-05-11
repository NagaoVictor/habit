#include <stdio.h>
#include <unistd.h>

int main(void){
  printf("PID: %d\n", getpid());
  while(1){
    sleep(1);
  }
  return 0;
}
