#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

void* producer(void *arg){
  for (int i=1; i<=10; i++ ){
    pthread_mutex_lock(&mutex);

    while(count == BUFFER_SIZE)
      pthread_cond_wait(&not_full, &mutex);
    
    buffer[count++] = i;
    printf("Produced %d\n", i);
    
    pthread_cond_signal(&not_empty);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void *consumer(void *arg){
  for (int i=1; i<=10; i++){
    pthread_mutex_lock(&mutex);
    while( count ==0)
        pthread_cond_wait(&not_empty, &mutex);  
    
    int value = buffer[--count];
    printf("Consumed %d\n", value);
  
    pthread_cond_signal(&not_full);
    pthread_mutex_unlock(&mutex);
  
    sleep(1);
  
  }
  return NULL;

}

int main(){
  pthread_t prod, cons;
  
  pthread_create(&prod, NULL, producer, NULL);
  pthread_create(&cons, NULL, consumer, NULL);

  pthread_join(prod, NULL);
  pthread_join(cons, NULL);

  return 0;
}




