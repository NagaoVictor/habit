#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd, len;
  char text[255];
  struct termios options;

  fd = open("/dev/serial0", O_RDWR | O_NDELAY | O_NOCTTY);
  if (fd < 0){
    perror("open");
    exit(1);
  }
  
  //set up serial port
  options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
  options.c_iflag = IGNPAR;
  options.c_oflag = 0;
  options.c_lflag = 0;


  // Apply the settings
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd, TCSANOW, &options);
  
  strcpy(text, "Raspberry Pi\n");
  len = strlen(text);
  len = write(fd, text, len);
  printf("Wrote %d bytes over UART\n", len);

  printf("You have 5s to send me some inpute data...\n");
  sleep(5);

  memset(text, 0, 255);
  len = read(fd, text, 255);
  printf("Received %d bytes\n", len);
  printf("Received string: %s\n", text);
  
  close(fd);
  return 0;

}
