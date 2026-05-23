#include <stdio.h>

typedef struct {
  char name[20];
  double grade;
} Student;

int main(){
  Student student[3] = {
    {"Victor1", 8.5},
    {"Victor2", 9.0},
    {"Victor3", 7.8}
  };

  for (int i = 0; i < 3; i++){
    printf("%s: %.1f\n", student[i].name, student[i].grade);

  }


}
