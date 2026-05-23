#include <stdio.h>
#include <math.h> // increase the -lm flags into compiler

float node(float x, float w){
  return x * w;
}

void bias(float * a){
  *a += 1;
}

float error(float predict, float real){
  return predict - real;
}

void coast(float * ct, float error){
  *ct = pow(error, 2) * 0.5; 

}

void weight_update(float* weight, float coast, float x_value ,float learing_rate){
   *weight = coast * x_value * learing_rate;
}


int main(){
  float x = 1.5;
  float w = 0.4;
  float predict = 0.75;   
  float custo;
  float lr = 0.005;
  float new_weight = w;
  float new_node = 0;

  printf("%.2f . %.2f + b\n", x, w);
  float n = node(x, w);
  bias(&n);
  printf("%.2f . %.2f + 1 = %.2f\n", x, w, n);  
  
  float error_calculated = error(n, predict);
  printf("Predict: %.3f, Calculated: %.3f\n", predict, n);
  printf("The error is %.3f\n", error_calculated);
  
  coast(&custo, error_calculated);
  printf("The coast: %.2f\n", custo);

  // After updated!
  printf("-----------------------------------------------------------------------");
  weight_update(&new_weight, custo, x, lr);
  new_node = node(x, new_weight);
  bias(&new_node);
  
  float new_error = error(new_node, predict);
  float new_coast = 0;
  coast(&new_coast, new_error);
  
  printf("%.2f . %.2f + b\n", x, new_weight);
  printf("%.2f . %.2f + b = %.2f\n", x, new_weight, new_node);
  printf("Predict: %.3f, Calculated: %.3f\n", predict, new_node);
  printf("The error is %.3f\n", new_error);
  printf("The coast: %.2f\n", new_coast);
 }
