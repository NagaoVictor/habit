#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fctnl.h>
#include <stdint.h>
#include <unistd.h>

//non-Canonical mode "Enter letter by letter without use enter keyboard command"



int main(int argc, char * argv[]){
  char buff[1024];
  int fd;
  
  fd = open(argv[1], O_RDWR);
  if(fd < 0){
    perror("Open");
    exit(1);
  }
  
  ssize_t reader = read(fd, buff, sizeof(buff));
  if(reader<0){
    perror("read");
    exit(1); 
   }
  
  ssize_t logger = write(fd, buff, sizeof)

   while(1){
      


  
  

  }




}
