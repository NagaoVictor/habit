#include <stdio.h>
#include <math.h>

  
#ifndef UPDATE_H
#define UPDATE_H

void update_nex(float * w, float x, float cost, float learning_rate){
  *w = x * cost * learning_rate;
}

void update_nyx(float *w, float x, float y, float learning_rate){
  *w = x * y * learning_rate;
}




#endif
