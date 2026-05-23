#include <stdio.h>

typedef struct {
  int speed;
  int running;

} Motor;


void start(Motor *m){
  m->running = 1; 
}

int main(){
  Motor motor = {80, 0};
  
  start(&motor);
  
  printf("Running = %d\n", motor.running);
  
  return 0;
}
