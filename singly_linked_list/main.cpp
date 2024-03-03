#include <iostream>
#include "linkedlist.h"



int main()
{
    // 1. instatiate the linked list with first value storing 6
    LinkedList my_list(6);

    // 2. insert nodes to the front
    for(int i=5; i>0; i--)
    {
        my_list.insert_front(i);
    }

    // 3. display the linked list
    my_list.display_list();

    // 4. Check if a value is present
    my_list.traverse_list(5);  // found
    my_list.traverse_list(11);  // not found

    // 5. insert at the end of list
    my_list.insert_end(7);

    // 6. display the linked list
    my_list.display_list();

    // 7. insert nodes between nodes
    my_list.insert_node(5, 0);

    // 8. display the linked list
    my_list.display_list();

    // 9. delete nodes
    my_list.delete_front();  // delete 1
    my_list.delete_front();  // delete 2
    my_list.display_list();
    my_list.delete_node(6);  // delete 6 in the middle
    my_list.display_list();

    // 10, delete all nodes
    // last iteration deletes node that doesn't exist
    for(int i=0; i<6; i++)
    {
        my_list.delete_front();

    }

    //11. insert node after deleting all nodes
    for(int i=5; i>0; i--)
    {
        my_list.insert_end(i);
    }
    my_list.display_list();


    return 0;
}
