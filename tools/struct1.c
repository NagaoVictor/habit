#include <stdio.h>

typedef struct {
  char name[50];
  int age;
} Person;


int main(){
  Person p = {"Victor", 29};
  
  printf("Name: %s\n", p.name);
  printf("Age: %d\n", p.age);
  
  return 0;
}
