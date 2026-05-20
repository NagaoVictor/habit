//i2c tools protocol install sudo apt-get install i2c-tools

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

int main(int argc, char * argv[]){
  int i2c_bus;
  uint8_t data[2];
  
  i2c_bus = open("/dev/i2c-i", O_RDWR);
  if (i2c_bus < 0){
    perror("Error opening I2C Bus");
    exit(1);
  }
  
  if(ioctl(i2c_bus, I2C_SLAVE, 0x20)<0){
    perror("ioctl");
    exit(1);
  }
  
  data[0] = 0x0;
  data[1] = 0xfe;

  if(write(i2c_bus, data, 2) != 2){
    perror("write");
    close(i2c_bus);
    exit(1);
  }

  
  data[0] = 0x14;
  if (argc > 1){
    data[1] = atoi(argv[1]) > 0;
  } else {
    perror("write data[0]");
    close(i2c_bus);
    exit(1);
  }
  
  if (read(i2c_bus, data, 1) != 1){
    perror("read");
    close(i2c_bus);
    exit(1);
  }

  printf("Button is %s\n", (data[0] & (1<<1)) > 0) ? "pressed" : "not pressed" ;
}
