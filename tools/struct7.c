#include <stdio.h>
#include <pthread.h>

typedef struct {
  int a;
  int b;

} ThreadArgs;

void *worker(void *arg){
  ThreadArgs *args = (ThreadArgs *)arg;
  printf("Sum = %d\n", args->a + args->b);
  return NULL;
}

int main(){
  pthread_t tid;

  ThreadArgs args = {10, 20};
  
  pthread_create(&tid, NULL, worker, &args);
  pthread_join(tid, NULL);

  return 0;
}
