#include <stdio.h>


typedef struct {
  int x;
  int y;
} Point;



void printer(Point p){
  printf("(%d, %d)\n", p.x, p.y);
}


int main(){
  Point p = {10, 20};
  printer(p);
  return 0;

}
