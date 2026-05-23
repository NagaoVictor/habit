#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE 10

typedef struct {
  char type;
  long timestamp;
} Event;

typedef struct {
  Event buffer[QUEUE_SIZE];
  int head;
  int tail;
  int count;
} MessageQueue;

// Initialize mq
void mq_init(MessageQueue * q){
  q->head = 0;
  q->tail = 0;
  q->count = 0;
}


// Enqueue
int mq_push(MessageQueue *q, Event e){
  if (q->count == QUEUE_SIZE)
    return -1;

  q->buffer[q->tail] = e;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
  q->count++;
  
  return 0;
}

// Dequeue
int mq_pop(MessageQueue *q, Event *e){
  if (q->count == 0)
    return -1;
  *e = q->buffer[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  q->count--;

  return 0;
}


