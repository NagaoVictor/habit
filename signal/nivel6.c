#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
  printf("Timeout\n");
}

int main(void){
  signal(SIGALRM, handler);
  alarm(3);

  printf("Waiting...\n");
  pause();
  return 0;
}
