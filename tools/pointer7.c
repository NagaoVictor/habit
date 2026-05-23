#include <stdio.h>

int main(){
  char name[] = "Victor";
  char *p = name;

  while (*p != '\0'){
    putchar(*p);
    p++;
  }
  
  putchar('\n');
 
  return 0;
}
