#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_data = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void *reader(void *arg){
  for (int i =0; i<3; i++){
    pthread_rwlock_rdlock(&rwlock);
    printf("Reader %ld: %d\n", (long)arg, shared_data);
    pthread_rwlock_unlock(&rwlock);
    sleep(1);
  }
  return NULL;
}

void *writer(void *arg){
  for (int i = 0; i < 3; i++){
    pthread_rwlock_wrlock(&rwlock);
    shared_data++;
    printf("Writer updated to %d\n", shared_data);
    pthread_rwlock_unlock(&rwlock);
    sleep(2);
  }
  return NULL;
}

int main(){
  pthread_t r1, r2, w1;

  pthread_create(&r1, NULL, reader, (void *)1);
  pthread_create(&r2, NULL, reader, (void *)2);
  pthread_create(&w1, NULL, writer, NULL);

  pthread_join(r1, NULL);
  pthread_join(r2, NULL);
  pthread_join(w1, NULL);

  return 0;
}
