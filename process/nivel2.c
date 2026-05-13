#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  if (pid == 0){
    printf("Son: PID=%d, PPID=%d\n",getpid(),getppid());
  } else {
    printf("Father: PID=%d, Son:%d\n", getpid(), pid);
  }
}
