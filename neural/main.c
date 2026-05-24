#include "node.h"
#include "update.h"
#include "activate.h"

int main(){
  float x = 0.5;
  float w = 0.23;
  float y = 2;

  float lr[4] = {1000, 0.001, 0.0001, 1};

  // NODE 
  float node_t = node(x,w); 
  printf("%.2f * %.2f = %.2f\n", x, w, node_t);
  
  // BIAS
  bias(&node_t);   
  printf("%.2f * %.2f + 1 = %.2f\n", x, w, node_t);

  // ACTIVATE
  sigmoid(&node_t, node_t);
  printf("Sigmoid: %.4f\n", node_t);

  // ERROR
  float error_t = error(y, node_t);
  printf("Error: %.2f\n", error_t);
  
  // COST
  float cost_t = cost(error_t);
  printf("%f\n", cost_t);

  // UPDATE   
//  for (int i = 0; i < 3; i++){
  //  update_nex(&w, x, cost_t, lr[i]);
   // update_nyx(&w, x, y, lr[i]);
   // printf("%.4f\n", w);  
  //}
  update_nex(&w, x, cost_t, lr[0]);
 // update_nyx(&w, x, y, lr[2]);

  // NEW WEIGHT
  printf("----------------------------------------\n");
  printf("%.2f", w);
  node_t = node(x,w); 
  printf("%.2f * %.2f = %.2f\n", x, w, node_t);
  sigmoid(&node_t, node_t);
  printf("Sigmoid: %.4f\n", node_t);
  error_t = error(y, node_t);
  printf("Error: %.2f\n", error_t);
 
}
