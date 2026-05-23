#include <stdio.h>

typedef struct {
  void (*start)(void);
  void (*stop)(void);
} Driver;

void motor_start(){
  //fill the method with the methods..
  printf("Motor started\n");
}

void motor_stop(){
  printf("Motor stopped\n");
}

int main(){
  Driver motor = {
    .start = motor_start,
    .stop = motor_stop,
  };

  motor.start();
  motor.stop();

  return 0;
}
