#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Command executor with timeout

pid_t child;
 
void timeout(int sig){
  kill(child, SIGKILL);
}

int main(){
  signal(SIGALRM, timeout);
  child = fork();
  
  if(child == 0){
    execlp("sleep", "sleep", "10", NULL );
    _exit(1);
  }
  
  alarm(3);
  
  int status;
  waitpid(child, &status, 0);
  
  if (WIFSIGNALED(status)){
    printf("Dead process by signal %d\n", WTERMSIG(status));
  }
  return 0;
}
