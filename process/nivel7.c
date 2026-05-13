#include <stdio.h>
#include <unistd.h>

int main(void){
  pid_t a = fork();
  
  if (a == 0){
    fork();
  } else {
    fork();
  }
  printf("PID=%d PPID=%d\n", getpid(), getppid());
}
