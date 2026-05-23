#include <stdio.h>

int main(){
  char *commands[] = {
    "forward", "backward", "left", "right", "stop"
  };
  
  int n = sizeof(commands) / sizeof(commands[0]);

  for (int i = 0; i < n; i ++){
    printf("%s\n", commands[i]);
  }
  return 0;

}
