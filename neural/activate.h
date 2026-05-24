#include <stdio.h>
#include <math.h>

#ifndef ACTIVATE_H
#define ACTIVATE_H

void sigmoid(float * node_t, float v){
  *node_t = 1/(1+exp(-v));
}
  




#endif
