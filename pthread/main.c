#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * worker(void *arg);

static int GLOBAL = 1;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int main(int argc, char const *argv[])
{
	/* code */
	pthread_t thread;
	
	// pthread_attr_t attr;
	
	// pthread_attr_init(&attr);
	if (pthread_create(&thread, NULL, worker,NULL) < 0 )
	{
		/* code */
		fprintf(stderr, "%s\n", "create thread failed");
	}
	//pthread_detach(thread);
	//sleep(1);
	for (int i = 0; i < 5; ++i)
	{
		pthread_mutex_lock(&mutex);
		GLOBAL ++;
		pthread_mutex_unlock(&mutex);	
		printf("Main thread update GLOBAL: %d\n",GLOBAL );
		sleep(1);
	}

	pthread_join(thread, NULL);
	printf("%s\n", "wait woker thread end");
	return 0;
}

void *worker(void *arg){

	printf("%s\n", "worker thread start");
	for (int i = 0; i < 5; ++i)
	{	
		pthread_mutex_lock(&mutex);
		GLOBAL ++;
		printf("Worker thread update GLOBAL: %d\n",GLOBAL );
		pthread_mutex_unlock(&mutex);	
		sleep(1);
	}

	return NULL;
}