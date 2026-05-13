#include <stdio.h>
#include <pthread.h>

void *worker(void *arg){
  int value = *(int *) arg;
  printf("Value = %d\n", value);
  return NULL;
}

int main(){
  pthread_t tid;
  int x = 42;
  
  pthread_create(&tid, NULL, worker, &x);
  pthread_join(tid, NULL);
}
