#ifndef QUEUE_H
#define QUEUE_H


class queue
{
private:
    int size;
    int head;
    int tail;
    int* arr = nullptr;

public:

    // default constructor
    queue();
    // parameterized constructor
    queue(int);
    // destructor
    ~queue();

    // member functions
    void enqueue(int);
    int dequeue();
    void display_queue();

};


#endif
