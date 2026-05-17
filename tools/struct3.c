#include <stdio.h>

typedef struct {
  int x;
  int y;
} Point;


void move(Point *p){
  p->x +=5;
  p->y +=5;
}

int main(){
  Point p = {1, 2};

  move(&p);

  printf("(%d, %d)\n", p.x, p.y);
  return 0;

}


