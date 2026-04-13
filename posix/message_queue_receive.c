#include <stdio.h>
#include <mqueue.h> // -lrt
#include <stdlib.h>

struct mq_attr attr = {
    .mq_flags=0,
    .mq_maxmsg=10,
    .mq_msgsize=256,
    .mq_curmsgs=0
};

int main(){
    mqd_t mqd;
    char buffer[256];
    unsigned prio;


    mqd = mq_open("/fila_demo", O_CREAT | O_RDWR, 0666, &attr);
    if (mqd==(mqd_t)-1){
        perror("mq_open");
        exit(1);
    }

    if (mq_receive(mqd, buffer, sizeof(buffer), &prio) == -1){
        perror("mq_receive");
        exit(1);
    }

    printf("Received: %s (prio %u)", buffer, prio);

    mq_close(mqd);
    mq_unlink("/file_demo");
    return 0;

}