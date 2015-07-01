#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

void *work(void *arg){

	int i = 0;
	for(i = 0; i < 5; i++){
		printf("Thread %d works\n", (int)arg);
	}

	return NULL;
}

int main(){

	pthread_t pid[MAX_THREADS];
	int i = 0;
	for(i = 0; i < MAX_THREADS; i++)
		pthread_create(&pid[i], NULL, work, (void*)i);

	for(i = 0; i < MAX_THREADS; i++)
		pthread_join(pid[i], NULL);

	return 0;
}
