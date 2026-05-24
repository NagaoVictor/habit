#include <stdio.h>
#include <math.h>


#ifndef NODE_H
#define NODE_H
float node(float x, float w){
  return x * w;
}

void bias(float * vary){
  *vary += 1;
}

float error(float y, float y_hat){
  return y - y_hat;
}

float cost(float error){
  return pow(error,2)*(0.5);
}
#endif
