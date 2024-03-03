/*
C++ program demonstrating a stack data structure. In this case,
the stack if implemented using c++ class where the stack is a dynamic array. Thus,
the same class can be used to instantiate objects that have different stack size.
*/

#include <iostream>
#include "stack.h"


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
