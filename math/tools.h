#include <stdio.h>
#include <stdlib.h>

#ifndef TOOLS_H
#define TOOLS_H

float power(float number, int potency){
  int n = 1;
  float value = number;
  while(n<potency){
    value*=number;
    n++;
  }
  return value;

}

int fact(int n){
  if (n==0){
    return 1;
  }
  if (n<0){
    n = n * (-1);
  }
  if (n!=1){
  n *= fact(n-1);
    n--;
  } else {
    return n;
  }
}


//Probability Mass Function
float pmf(int n, int x, float probability){
   int above = fact(n);
   int below = fact(x)*fact(n-x);
   int combination = above / below;  
   return  combination* power(probability, x)*power(1-probability,n-x);
}

//Probability Density Function
float pdf(int n, int x, float probability){
  float density;
  for (int x = 0; x<=n; x++){
    density += pmf(n, x, probability);
  }
  return density;

}


#endif
