/**
 *
 * This is a doubly linked list built with Object oriented approach.
 * Each node has a next and previous pointer of the same type.
 * A new node is created dynamically during runtime whenever
 * the insert function is called.
 *
*/


#include <iostream>
#include "doubly_linked.h"


int main()
{
    // 1. Instantiate a linked list object
    LinkedList my_list(6);

    // 2. insert from front
    for(int i=5; i>0; i--)
    {
        my_list.insert_front(i);
    }
    my_list.traverse_forward();

    // 3. insert from rear
    for(int i=7; i<=10; i++)
    {
        my_list.insert_rear(i);
    }
    my_list.traverse_backward();

    // 4. insert node before node 3
    my_list.insert_node(3, 100);
    my_list.traverse_forward();

    // 5. traverse the list backwards
    my_list.traverse_backward();

    // 6. delete all nodes and try deleting one extra
    for(int i=0; i<12; i++)
    {
        std::cout<<"\n";
        my_list.delete_front();
        my_list.traverse_forward();
    }

    // 7/ insert again upon deleting all nodes
    for(int i=5; i>0; i--)
    {
        my_list.insert_front(i);
    }
    my_list.traverse_forward();

    return 0;
}
