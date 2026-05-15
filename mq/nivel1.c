#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 256

int main(){
  mqd_t mq;
  struct mq_attr attr;
  char buffer[MAX_MSG_SIZE];
  unsigned int priority;

 // queue settings 
  attr.mq_flags = 0; // Block mode
  attr.mq_maxmsg = 10; // maximum 10 message 
  attr.mq_msgsize = MAX_MSG_SIZE; // Character maximum size
  attr.mq_curmsgs = 0; // Actual number message 
  
  //Create or open queue
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);  
  if (mq == (mqd_t)-1){
     perror("mq_open");
     exit(EXIT_FAILURE);
  }

  printf("Queue created successfully\n");
  
  const char *message = "Hello from POSIX Message Queue!";
  
  //Message that it'll send
  if (mq_send(mq, message, strlen(message) + 1, 0) == -1){
    perror("mq_send");
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    exit(EXIT_FAILURE);
  } 

  printf("Message sent: %s\n", message);

  // Message received
  ssize_t bytes = mq_receive(mq, buffer, sizeof(buffer), &priority);
  if (bytes==-1){
    perror("mq_receive");
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    exit(EXIT_FAILURE);
  }
  
  printf("Message received: %s\n", buffer);
  printf("Priority: %u\n", priority);
  printf("Bytes received: %zd\n", bytes);

  // Close file descriptor of file
  if(mq_close(mq) == -1){
    perror("mq_close");
    exit(EXIT_FAILURE);
  }

  // Remove the queue of system
  if (mq_unlink(QUEUE_NAME) == -1){
    perror("mq_unlink");
    exit(EXIT_FAILURE);
  }
  
  printf("Queue removed successfully.\n");
  
  return 0;


}
