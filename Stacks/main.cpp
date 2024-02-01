/*
C++ program demonstrating a stack data structure. In this case,
the stack if implemented using c++ class where the stack is a dynamic array. Thus,
the same class can be used to instantiate objects that have different stack size.
*/

#include <iostream>


class stack
{

private:
    int size;
    int top = -1;
    int* arr = NULL;

public:

    // default constructor
    stack(){}

    // parameterized constructor
    stack(int input_size)
    {
        size = input_size;
        arr = new int [size];  // dynamically allocate array
    }

    // destructor
    ~stack()
    {
        delete [] arr;  // deallocate dynamic memory
    }

    bool is_not_empty()
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

    void push(int value)
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

    int pop()
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

    void peak()
    {
        if (is_not_empty())
        {
            std::cout<<"Top item is "<<arr[top]<<std::endl;
        }
    }

    void display_stack()
    {
        for (int i=0; i<=top; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

};


int main()
{
    // 1. create a stack of size 5
    stack my_Stack(5);

    // 2, push items to the stack
    for ( int i=0; i<7; i++)
    {
        my_Stack.push(i+1);
    }

    //3. display the entire stack
    my_Stack.display_stack();

    //4. pop elemets
    std::cout<<my_Stack.pop()<<std::endl;  // remove 5
    std::cout<<my_Stack.pop()<<std::endl;  // remove 4

    // 5. peak last item
    my_Stack.peak();

    // 6. siaply stack after modifying
    my_Stack.display_stack();

    return 0;
}
