#include <stdio.h>
#include <termios.h>
#include <unistd.h>

//non-Canonical mode "Enter letter by letter without use enter keyboard command"

struct termios oldt, newt;

void enable_raw_mode(){
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_cc[VMIN] = 1; // key by key
  newt.c_cc[VTIME] = 0; // No timeout
  
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); // TCSANOW allow change the settings without wait the data queue  
}

void disable_raw_mode(){
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

}



int main(){
  char c;
  
  enable_raw_mode();
  printf("Enter some letter\n");
   while(1){
      read(STDIN_FILENO, &c, 1);
      
      printf("Key: %c\n", c);
      
      if (c == 'q') break;
     // if (c == 'v') printf("V de victor\n");
  }
  disable_raw_mode();
  return 0;
}
