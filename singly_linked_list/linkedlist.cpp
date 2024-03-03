#include <iostream>
#include "linkedlist.h"


// default constructor
LinkedList::LinkedList(){}


// parameterized constructor
LinkedList::LinkedList(int value)
{
    headptr = new Node;
    headptr->value = value;
}


// destructor
LinkedList::~LinkedList()
{
    // if any node is left at the end of program
    if(headptr!=NULL)
    {
        Node* temp = NULL;

        while (headptr!=NULL)
        {
            temp = headptr;
            headptr = (*headptr).nextptr;
            delete temp;
        }
    }
}


// insert new node to the front O(1).
void LinkedList::insert_front(int value)
{
    Node* new_node = new Node;
    (*new_node).value = value;

    // if list is empty
    if(headptr==NULL)
    {
        headptr = new_node;
    }

    else
    {
        (*new_node).nextptr = headptr;
        headptr = new_node;
    }
}


// insert at the end O(n)
void LinkedList::insert_end(int value)
{
    // if list is empty
    if(headptr==NULL)
    {
        Node* new_node = new Node;
        (*new_node).value = value;
        headptr = new_node;
    }
    else
    {
        traverse_list(value, true);
    }
}


// to insert node in the middle of the list before the target key O(n)
void LinkedList::insert_node(int key, int value)
{
    // if list is empty
    if(headptr==NULL)
    {
        Node* new_node = new Node;
        (*new_node).value = value;
        headptr = new_node;
    }

    else
    {
        Node* next_node = headptr;
        Node* prev_node = NULL;

        while(next_node!=NULL)
        {
            // traverse the list simply to check if key is present
            if((*next_node).value == key)
            {
                Node* new_node = new Node;
                new_node->value = value;
                prev_node->nextptr = new_node;
                new_node->nextptr = next_node;
                break;
            }

            // move to next node in list till NULL
            prev_node = next_node;
            next_node = (*next_node).nextptr;;
        }
    }
}


// traverse list and look for a particular node O(n)
void LinkedList::traverse_list(int value, bool insert_node)
{
    if(headptr)
    {
        Node* next_node = headptr;
        Node* prev_node = NULL;
        int index = 0;
        bool node_found = false;
        while(next_node!=NULL)
        {
            // traverse the list simply to check if value is present
            if(insert_node==false && (*next_node).value == value)
            {
                std::cout<<"Value: "<<value<<" present at index "<<index<<"\n";
                node_found = true;
            }

            // move to next node in list till last node
            prev_node = next_node;
            next_node = (*next_node).nextptr;
            index++;
        }

        if(!node_found && insert_node==false)
        {
            std::cout<<"Value: "<<value<<" not found.\n";
        }

        // insert a new node at rear of list
        if(insert_node==true)
        {
            Node* new_node = new Node;
            new_node->value = value;
            prev_node->nextptr=new_node;
        }
    }

    else
    {
        std::cout<<"List is empty\n";
    }
}


// delete front node O(1)
void LinkedList::delete_front()
{
    if(headptr!=NULL)
    {
        Node* temp = NULL;
        temp = headptr;
        headptr = headptr->nextptr;
        delete temp;
    }

    else
    {
        std::cout<<"List is empty\n";
    }
}


// to delete node in any part of the list
void LinkedList::delete_node(int key)
{
    Node* next_node = headptr;
    Node* prev_node = NULL;

    // treaverse the lsit to find the node
    while(next_node!=NULL)
    {
        // traverse the list simply to check if value is present
        if((*next_node).value == key)
        {
            Node* temp = NULL;
            temp = next_node;
            prev_node->nextptr = next_node->nextptr;
            delete temp;
            break;
        }

        // move to next node in list till NULL
        prev_node = next_node;
        next_node = (*next_node).nextptr;
    }

}


// Traverse whole list to display O(n).
void LinkedList::display_list()
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
