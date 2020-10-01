#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <iostream>
#include <fifo.h>

extern pthread_mutex_t sharedVariableMutex;
//extern int32_t gSharedVariable;
extern Fifo newFifo;

void *incrementTask(void *param)
{
    while (1)
    {
        /* Delay for 3 seconds. */
        sleep(3);
        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);
        //gSharedVariable++;
        newFifo.put(rand() % 100);
        //std::cout<<"Increment Task: shared var is: ";
        //std::cout<< gSharedVariable<<std::endl;
        
        /* Release the mutex for other task to use. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}