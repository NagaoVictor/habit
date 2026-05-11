#include <stdio.h>
#include <unistd.h> //fork()

int main(void){
  pid_t pid = fork();
  
  if (pid == 0){
    printf("Child process\n");
    printf("PID: %d\n", getpid());  
  }
  else {
    printf("Parent process\n");
    printf("Child PID: %d\n", pid);
  }
  return 0;


}
