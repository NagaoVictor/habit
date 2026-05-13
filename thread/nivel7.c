#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Wait data, notification or data sync

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void *consumer(void *arg){
  pthread_mutex_lock(&mutex);
  
  while(!ready){
    printf("Consumer waiting...\n");
    pthread_cond_wait(&cond, &mutex);
  }
  
  printf("Consumer resumed.\n");
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *producer(void *arg){
  sleep(2);
  
  pthread_mutex_lock(&mutex);
  ready = 1;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);  
  
  return NULL;
}

int main(){
  pthread_t t1, t2;
  pthread_create(&t1, NULL, consumer, NULL);
  pthread_create(&t2, NULL, producer, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}

