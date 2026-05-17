#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 10

typedef struct {
  char type;
  long timestamp;
} Event;

int main(){
  Evenr queue[MAX_EVENTS];
  int count = 0;

  queue[count++] = (Event){'F', time(NULL)};
  queue[count++] = (Event){'L', time(NULL)};
  queue[count++] = (Event){'S', time(NULL)};

  for (int i = 0; i < count; i++){
    printf("Event %c in to %ld\n", queue[i].type, queue[i].timestamp);
  }
  return 0;
}
