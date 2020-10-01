#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <fifo.h>

extern Fifo newFifo;
extern pthread_mutex_t sharedVariableMutex;
//extern int32_t gSharedVariable;

void *decrementTask(void *param)
{
    while (1)
    {
        /* Delay for 7 seconds. */
        sleep(7);
        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);
        //gSharedVariable--;
        //std::cout<<"Decrement Task: shared var is: ";
        //std::cout<<gSharedVariable<<std::endl;
        newFifo.get();
        /* Release the mugSharedVariabletex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}