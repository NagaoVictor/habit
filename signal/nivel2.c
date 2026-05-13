#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler(int sig){
  write(STDOUT_FILENO, "SIGINT Received\n", 16);
}

int main(void){
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));

  sa.sa_handler = handler;
  sigaction(SIGINT, &sa, NULL);
  while(1)
    pause();
}
