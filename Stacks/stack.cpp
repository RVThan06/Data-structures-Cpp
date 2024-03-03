#include <iostream>
#include "stack.h"


stack::stack(){}


// parameterized constructor
stack::stack(int input_size)
{
    size = input_size;
    arr = new int [size];  // dynamically allocate array
}


// destructor
stack::~stack()
{
    delete[] arr;  // deallocate dynamic memory
}


bool stack::is_not_empty()
{
    if (top > -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void stack::push(int value)
{
    if (top != size-1)
    {
        top = top + 1;
        arr[top] = value;
    }
    else
    {
        std::cout<<"The stack is full thus item "<<value<<" cannot be added"<<std::endl;
    }
}


int stack::pop()
{
    if (is_not_empty())
    {
        int temp = arr[top];
        top = top-1;
        return temp;
    }
    else
    {
        return 0;
    }
}


void stack::peak()
{
    if (is_not_empty())
    {
        std::cout<<"Top item is "<<arr[top]<<std::endl;
    }
}


void stack::display_stack()
{
    for (int i=0; i<=top; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
