#include <stdio.h>
#include <pthread.h> //gcc nivel1.c -o cc -pthread

void *worker(void * arg){
  printf("Hello from thread!\n");
  return NULL;
}

int main(void){
  pthread_t tid;
  
  pthread_create(&tid, NULL, worker, NULL);
  pthread_join(tid, NULL);

  return 0;
}
