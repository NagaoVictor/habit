#include <stdio.h>
#include <pthread.h> // Compiler -pthread
#include <stdlib.h>


typedef struct {
	int a;
	int b;
	int c;
} ThreadArgs;


// parameter construct.


void * sum(void * arg){
	ThreadArgs * params = (ThreadArgs*) arg; // Void parameter receive some type.	
	printf("Soma: %d\n", params->a + params->b + params->c);
	}


int main(){
	
	int s;
	pthread_t thread;

	// Parameter  settings
	ThreadArgs * args = malloc(sizeof(ThreadArgs));
	args->a = 10;
	args->b = 20;
	args->c = 60;

	s = pthread_create(&thread, NULL, sum,(void*)args);
	if (s != 0){
		perror("Create failed\n");
		exit(EXIT_FAILURE);
	}
	
	s = pthread_join(thread, NULL);
	if (s != 0){
		perror("Join failed\n");
		exit(EXIT_FAILURE);	
	}
	free(args);
	exit(EXIT_SUCCESS);

}
