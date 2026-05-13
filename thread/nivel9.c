#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define NUM_TASKS 10

int next_task = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg){
  while(1) {
    pthread_mutex_lock(&mutex);
    
    if (next_task >= NUM_TASKS){
      pthread_mutex_unlock(&mutex);
      break; 
    }

    int task = next_task++;
    pthread_mutex_unlock(&mutex); 
    
    printf("Thread %lu processing task %d\n", (unsigned long)pthread_self(), task);
    
    sleep(1);
    }
  return NULL;
}

int main(){
  pthread_t threads[NUM_THREADS];
  
  for (int i = 0; i < NUM_THREADS; i++){
    pthread_create(&threads[i], NULL, worker, NULL);

  }
  
  for (int i = 0; i < NUM_THREADS; i++){
    pthread_join(threads[i], NULL);
  
  }

  return 0;
}
