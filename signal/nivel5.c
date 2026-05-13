#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
  printf("PID = %d\n", getpid());
  printf("Paused itself ...\n");
  
  raise(SIGSTOP);
  
  printf("Continuing!\n");
  return 0;
}
