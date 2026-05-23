#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>

struct termios oldk, newk;

void enable_raw_mode(){
  tcgetattr(STDIN_FILENO, &oldk);
  newk = oldk;

  newk.c_lflag &= ~(ICANON | ECHO);
  newk.c_cc[VMIN] = 1;
  newk.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &newk);
 }

void disable_raw_mode(){
  tcsetattr(STDIN_FILENO, TCSANOW, &oldk);
}


int main(){
  char c;
  int fd;
  fd = open("data.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
  if (fd<0){
    perror("open");
    exit(1);
  }
  enable_raw_mode();
   
  printf("Enter some char or q to quit");
  while(1){
    if (c == 'q'){
      break;
    }
   printf("%c\n", c); 
   read(STDIN_FILENO, &c, 1);
    write(fd, &c, 1);
  }
  disable_raw_mode();
  close(fd);
  
}


