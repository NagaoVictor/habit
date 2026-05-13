#include <unistd.h>
#include <stdlib.h>

int main(void){
  if (fork()>0)
     exit(0);


  setsid();
  chdir("/");
  close(0);
  close(1);
  close(2);

  while(1){
    sleep(60);
  }
}
