/**
 *
 * This is a doubly linked list built with Object oriented approach.
 * Each node has a next and previous pointer of the same type.
 * A new node is created dynamically during runtime whenever
 * the insert function is called.
 *
*/


#include <iostream>


struct Node
{
    int value;
    Node* prevptr = NULL;
    Node* nextptr = NULL;
};


class LinkedList
{
private:
    Node* headptr = NULL;
    Node* tailptr = NULL;

public:

    // default constructor
    LinkedList(){}


    // parameterized constructor
    LinkedList(int value)
    {
        Node* new_node = new Node;
        new_node->value = value;
        headptr = new_node;
        tailptr = new_node;
    }

    // destructor
    ~LinkedList()
    {
        // if any node is left at end of program
        if(headptr!=NULL)
        {
            // delete each node by traversing the list till NULL
            Node* temp = NULL;

            while (headptr!=NULL)
            {
                // Node* temp = NULL; not sure where to insert this
                temp = headptr;
                headptr = (*headptr).nextptr;
                delete temp;
            }

        }
    }

    // insert node from head O(1)
    void insert_front(int value)
    {
        Node* new_node = new Node;
        new_node->value = value;

        // when list is empty
        if(headptr==NULL)
        {
            headptr = new_node;
            tailptr = new_node;
        }

        else
        {
            // when list is not empty
            new_node->nextptr = headptr;
            headptr->prevptr = new_node;
            headptr = new_node;
        }
    }


    // insert from the end O(1)
    void insert_rear(int value)
    {
        Node* new_node = new Node;
        new_node->value = value;

        // when list is empty
        if(tailptr==NULL)
        {
            headptr = new_node;
            tailptr = new_node;
        }

        else
        {
            // when list is not empty
            tailptr->nextptr = new_node;
            new_node->prevptr = tailptr;
            tailptr = new_node;
        }

    }

    // insert in middle O(n)
    void insert_node(int key, int value)
    {
        Node* next_node = headptr;
        Node* prev_node = NULL;

        Node* new_node = new Node;
        new_node->value = value;

        // insert in middle when list is not empty
        if(headptr!=NULL)
        {
            while(next_node!=NULL)
            {
                // traverse the list simply to check if key is present
                if((*next_node).value == key)
                {
                    prev_node->nextptr = new_node;
                    new_node->prevptr = prev_node;
                    new_node->nextptr = next_node;
                    next_node->prevptr = new_node;
                    break;
                }

                // move to next node in list till NULL
                prev_node = next_node;
                next_node = (*next_node).nextptr;;
            }
        }

        // if inserting into empty list
        else
        {
            headptr = new_node;
            tailptr = new_node;
        }

    }


    // to delete node from head O(1)
    void delete_front()
    {
        if(headptr!=NULL)
        {
            Node* temp = NULL;
            if(headptr!=tailptr)
            {
                headptr->nextptr->prevptr = NULL;
            }
            temp = headptr;
            std::cout<<"Delete "<<temp->value<<"\n";
            headptr = headptr->nextptr;
            delete temp;
        }

        else
        {
            std::cout<<"The list is empty thus no further deletion.\n";
        }
    }

    // display list by traversing from head O(n)
    void traverse_forward()
    {
        Node* next_nodeptr = headptr;
        while(next_nodeptr!=NULL)
        {
            std::cout<<(*next_nodeptr).value;
            next_nodeptr = (*next_nodeptr).nextptr;

            if (next_nodeptr!=NULL)
            {
                std::cout<<"-->";
            }
        }
        std::cout<<"\n";
    }

    // traverse from tall and display list O(n)
    void traverse_backward()
    {
        Node* next_nodeptr = tailptr;
        while(next_nodeptr!=NULL)
        {
            std::cout<<(*next_nodeptr).value;
            next_nodeptr = (*next_nodeptr).prevptr;

            if(next_nodeptr!=NULL)
            {
                std::cout<<"-->";
            }
        }
        std::cout<<"\n";
    }


};



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
