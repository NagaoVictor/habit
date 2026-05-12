#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();
  
  if (pid == 0){
    printf("PID=%d PPID=%d\n",getpid(), getppid());
    fork();
    if(pid == 0){
        printf("PID=%d PPID=%d\n", getpid(), getppid());
    } else {
         fork();
        printf("PID=%d PPID=%d\n",getpid(),getppid());
    }
  }
  else{
    printf("PID=%d PPID=%d\n", getpid(), getppid());
    wait(NULL);
   }
}
