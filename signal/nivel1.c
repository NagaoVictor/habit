#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
  printf("SIGINT received (%d)\n", sig);
}

int main(){
  signal(SIGINT, handler); // Call the handle method if (Crtl + C) was invoked.
  while(1){
    printf("Rolling...\n");
    sleep(1);
  }
}
