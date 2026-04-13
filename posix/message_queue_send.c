#include <mqueue.h> // Compiler -lrt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    mqd_t mqd;

    mqd = mq_open("/fila_demo", O_CREAT | O_WRONLY, 0666, NULL);
    if (mqd == (mqd_t)-1){
        perror("mq_open");
        exit(1);
    }

    const char *msg= "Ola MQ!";
    
    if (mq_send(mqd, msg, strlen(msg)+1, 0)==-1){
        perror("mq_send");
        exit(1);
    }

    mq_close(mqd);
    return 0;


}