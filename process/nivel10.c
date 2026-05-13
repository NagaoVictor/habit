#include <unistd.h>
#include <stdlib.h>

int main(void){
  pid_t pid = fork();
  
  if (pid > 0)
    exit(0);

  setsid();
  
  pid = fork();
  
  if(pid>0)
    exit(0);
  
  while(1){sleep(60);}


}
