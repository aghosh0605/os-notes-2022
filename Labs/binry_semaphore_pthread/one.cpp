#include <stdio.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
 sem_wait(&mutex); 
 printf("\nEntered..\n");
 sleep(4);
 printf("\nJust Exiting...\n"); 
 sem_post(&mutex);
 return 0;
}
int main()
{
 sem_init(&mutex, 0, 1); 
 pthread_t t1,t2;
 pthread_create(&t1,NULL,thread,NULL); 
 sleep(2); 
 pthread_create(&t2,NULL,thread,NULL); 
 pthread_join(t1,NULL); 
 pthread_join(t2,NULL); 
 sem_destroy(&mutex);
 return 0;
}
