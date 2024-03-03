#include <iostream>
#include "queue.h"


// default constructor
queue::queue(){}


// parameterized constructor
queue::queue(int size)
{
    this->size = size;
    head = -1;
    tail = -1;
    arr = new int[this->size];
}


// destructor
queue::~queue()
{
    delete [] arr;
}


void queue::enqueue(int value)
{
    // check if queue is full
    if (head == (tail+1)%size)
    {
        std::cout<<"The queue is full so "<<value<<" cannot be added\n";
    }

    // check if queue is empty
    else if(head==-1 && tail==-1)
    {
        head = 0;
        tail = 0;
        arr[tail] = value;
    }

    else
    {
        tail = (tail+1)%size;
        arr[tail] = value;
    }
}


// to pop the first-in element
int queue::dequeue()
{
    // check if queue is empty
    if (head==-1 && tail==-1)
    {
        std::cout<<"queue is empty\n";
    }

    // check if 0nly one element is left
    else if (head == tail)
    {
        int temp = arr[head];
        // reset to -1 if queue is empty
        head = -1;
        tail = -1;
        return temp;
    }

    else
    {
        int temp = arr[head];
        head = (head+1)%size;
        return temp;
    }
}


void queue::display_queue()
{
    for(int i=head; i!=tail; i=(i+1)%size)
    {
        std::cout<<arr[i]<<" ";
    }
    // print last item
    std::cout<<arr[tail]<<std::endl;
}
