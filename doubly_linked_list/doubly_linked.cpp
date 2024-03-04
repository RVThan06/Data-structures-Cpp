#include <iostream>
#include "doubly_linked.h"



// default constructor
LinkedList::LinkedList(){}


// parameterized constructor
LinkedList::LinkedList(int value)
{
    Node* new_node = new Node;
    new_node->value = value;
    headptr = new_node;
    tailptr = new_node;
}


// destructor
LinkedList::~LinkedList()
{
    // if any node is left at end of program
    if(headptr!=nullptr)
    {
        // delete each node by traversing the list till nullptr
        Node* temp = nullptr;

        while (headptr!=nullptr)
        {
            // Node* temp = nullptr; not sure where to insert this
            temp = headptr;
            headptr = (*headptr).nextptr;
            delete temp;
        }

    }
}


// insert node from head O(1)
void LinkedList::insert_front(int value)
{
    Node* new_node = new Node;
    new_node->value = value;

    // when list is empty
    if(headptr==nullptr)
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
void LinkedList::insert_rear(int value)
{
    Node* new_node = new Node;
    new_node->value = value;

    // when list is empty
    if(tailptr==nullptr)
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
void LinkedList::insert_node(int key, int value)
{
    Node* next_node = headptr;
    Node* prev_node = nullptr;

    Node* new_node = new Node;
    new_node->value = value;

    // insert in middle when list is not empty
    if(headptr!=nullptr)
    {
        while(next_node!=nullptr)
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

            // move to next node in list till nullptr
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
void LinkedList::delete_front()
{
    if(headptr!=nullptr)
    {
        Node* temp = nullptr;
        if(headptr!=tailptr)
        {
            headptr->nextptr->prevptr = nullptr;
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
void LinkedList::traverse_forward()
{
    Node* next_nodeptr = headptr;
    while(next_nodeptr!=nullptr)
    {
        std::cout<<(*next_nodeptr).value;
        next_nodeptr = (*next_nodeptr).nextptr;

        if (next_nodeptr!=nullptr)
        {
            std::cout<<"-->";
        }
    }
    std::cout<<"\n";
}


// traverse from tall and display list O(n)
void LinkedList::traverse_backward()
{
    Node* next_nodeptr = tailptr;
    while(next_nodeptr!=nullptr)
    {
        std::cout<<(*next_nodeptr).value;
        next_nodeptr = (*next_nodeptr).prevptr;

        if(next_nodeptr!=nullptr)
        {
            std::cout<<"-->";
        }
    }
    std::cout<<"\n";
}
