#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *worker(void *arg){
  int *result = malloc(sizeof(int));
  *result = 100;
  return result;
}

int main(void){
  pthread_t tid;
  int *result;

  pthread_create(&tid, NULL, worker, NULL);
  pthread_join(tid, (void **)&result);

  printf("Result = %d\n", *result);  
  free(result);
}
