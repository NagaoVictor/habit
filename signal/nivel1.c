#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
  printf("SIGINT received (%d)\n", sig);
}

int main(){
  signal(SIGINT, handler);
  while(1){
    printf("Rolling...\n");
    sleep(1);
  }
}
