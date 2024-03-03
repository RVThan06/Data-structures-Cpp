/*
c++ implenmentation of circular queue. In this case, the queue was implemented
usinf classes where the size of queue is a dynamicly allocated array. This allows
the same class to be used for the instantiating queue objects with different size.
*/

#include <iostream>
#include "queue.h"


int main()
{

    // 1. instantiate a queue obj with size 5
    queue my_queue(5);

    // 2. add items to the queue
    for(int i=0; i<6; i++)
    {
        my_queue.enqueue(i+1);
    }

    // 3. display the enqueue
    my_queue.display_queue();

    // 4. remove items
    std::cout<<my_queue.dequeue()<<std::endl;
    std::cout<<my_queue.dequeue()<<std::endl;

    // 5. print the updated queue
    my_queue.display_queue();

    return 0;
}
