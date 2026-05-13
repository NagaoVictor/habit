#include <stdio.h>
#include <pthread.h>

//Race condition simulation

int counter=0;

void *worker(void *arg){
  for (long i =0; i<1000000; i++){
    counter++; //No atomic operation...
  }
  return NULL;
}

int main(void){
  pthread_t t1, t2;

  pthread_create(&t1, NULL, worker, NULL);
  pthread_create(&t2, NULL, worker, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Counter = %ld\n", counter);
  printf("Expected = 2000000\n");

  return 0;
}
