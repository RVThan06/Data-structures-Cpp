/*
c++ implenmentation of circular queue. In this case, the queue was implemented
usinf classes where the size of queue is a dynamicly allocated array. This allows
the same class to be used for the instantiating queue objects with different size.
*/

#include <iostream>


class queue
{
private:
    int size;
    int head;
    int tail;
    int* arr;

public:

    // default constructor
    queue(){}

    // parameterized constructor
    queue(int size)
    {
        this->size = size;
        head = -1;
        tail = -1;
        arr = new int[this->size];
    }

    // destructor
    ~queue()
    {
        delete [] arr;
    }

    void enqueue(int value)
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
    int dequeue()
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

    void display_queue()
    {
        for(int i=head; i!=tail; i=(i+1)%size)
        {
            std::cout<<arr[i]<<" ";
        }
        // print last item
        std::cout<<arr[tail]<<std::endl;
    }

};



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
