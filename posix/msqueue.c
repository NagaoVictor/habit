#include <stdio.h>
#include <mqueue.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
  if  (argc != 2 || strcmp(argv[1], "--help") == 0){
    fprinf("%s mq-name\n", argv[0]);

  }
  if (mq_unlink(argv[1])==-1){
    perror("mq_unlink");
    exit(SUCCESS);
  } 





}

