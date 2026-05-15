#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

typedef struct {
  char type;
  long timestamp;
} Event;

// Struct method

void reg(char c){
   Event e;
   e.type = c;
   e.timestamp=time(NULL);
   
   if (c == 'w' || c == 'W'){
      printf("Forward | %ld Seconds since 1970\n", e.timestamp);
    } else if (c == 's' || c == 'S'){
       printf("Backward | %ld Seconds since 1970\n", e.timestamp);
    } else if (c == 'a' || c == 'A'){
      printf("Leftside | %ld Seconds since 1970\n", e.timestamp);
    } else if (c == 'd' || c == 'D'){
      printf("Rightside | %ld Seconds since 1970\n", e.timestamp);
    } else {
      printf("Command: %c | %ld Seconds since 1970\n", e.type, e.timestamp);
    }
}


struct termios newt, oldt;

void enable_raw_mode(){
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
}

void disable_raw_mode(){
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}


int main(){
  char c;
  enable_raw_mode();
  while(1){
    read(STDIN_FILENO, &c, 1);
    
    if (c == 'q' | c == 'Q') break;
    reg(c);
  }
  disable_raw_mode();
  return 0;
}

