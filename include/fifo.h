#include <iostream>
#include <unistd.h>
#include <sys/types.h>

#ifndef FIFO_H
#define FIFO_H

const int FIFO_SIZE = 5;

class Fifo
{
public:
    Fifo()
    {
        highest = 0;
        lowest = 0;
        counter = 1;
        for (int i=0; i < FIFO_SIZE; i++)
        {
            buffer[i]  = 0;
        }
    }

    int get()
    {
        //sets low if your getting from a full queue
        if (highest == 0)
        {
            std::cout<<"Error, no value in fifo, returning 0"<<std::endl;
            //Serial.println("Error, no value in fifo, returning 0");
            return 0;
        }
        else
        {
            int retVal = buffer[0];

            for (int i = 0; i < highest; i++)
            {
                buffer[i] = buffer[i+1];
            }
            highest--;
            std::cout<<"Popping: "<<retVal<<std::endl;
            std::cout<<"Current queue: ";
            for (int i= 0; i < highest; i++)
            {
                std::cout<<buffer[i]<<" ";
            }
            std::cout<<std::endl;
            return retVal;
        }
    }

    void put(int item)
    {
        if(highest == FIFO_SIZE)
        {
            std::cout<<"Queue full, come back later!"<<std::endl;
            //Serial.print("queue full, come back later");
        }
        else
        {
            buffer[highest] = counter;
            std::cout<<"Putting: "<<counter<<std::endl;
            highest++;
            counter++;
            std::cout<<"Current queue: ";
            for (int i= 0; i < highest; i++)
            {
                std::cout<<buffer[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    bool is_empty()
    {
        if (highest == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_full()
    {
        if (highest == FIFO_SIZE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void reset()
    {
        highest = 0;
        lowest = 0;
        for (int i=0; i < FIFO_SIZE; i++)
        {
            buffer[i]  = 0;
        }
    }
    
private:
    int buffer[FIFO_SIZE];
    int lowest;
    int highest;
    int counter;
};

#endif // FIFO_H
