#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char type;
  long timestamp;
  char description[64];
} Event;

void process_event(Event *e){
  printf("Type: %c\n", e->type);
  printf("Timestamp: %ld\n", e->timestamp);
  printf("Description: %s\n", e->description);
}

int main(){
  Event e;
  
  e.type = 'F';
  e.timestamp = time(NULL);
  strcpy(e.description, "Move Forward");
  
  process_event(&e);

  return 0;

}
