#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
  int value;
  struct Node *next;
} Node;


int main(){
  Node *a = malloc(sizeof(Node));
  Node *b = malloc(sizeof(Node));

  a->value = 10;
  a->next = b;

  b->value = 20;
  b->next = NULL;

  
  Node *curr = a;
  while (curr){
    printf("%d\n", curr->value);
    curr = curr->next;
  }  

  free(a);
  free(b);

  return 0;
}
