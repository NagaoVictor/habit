#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
  int chip_fd;
  int line_fd;
  int line;
} GPIODevice;

GPIODevice gpio_init(){
  GPIODevice dev;

  dev.chip_fd = open("/dev/gpiochip0", O_RDWR);
  dev.line_fd = 100;
  dev.line = 6;
  
  return dev;
}

void gpio_close(GPIODevice *dev){
  close(dev->line_fd);
  close(dev->chip_fd);
}

int main(){
  GPIODevice gpio = gpio_init();
   
  printf("GPIO line %d starting...\n", gpio.line);
  
  gpio_close(&gpio);
  return 0;
}
