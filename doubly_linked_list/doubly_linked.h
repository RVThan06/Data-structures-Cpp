#include "node.h"
#ifndef DOUBLY_LINKED_H
#define DOUBLY_LINKED_H


class LinkedList
{
private:
    Node* headptr = nullptr;
    Node* tailptr = nullptr;

public:

    // default constructor
    LinkedList();

    // parameterized constructor
    LinkedList(int);

    // destructor
    ~LinkedList();

    // member functions
    void insert_front(int);
    void insert_rear(int);
    void insert_node(int, int);
    void delete_front();
    void traverse_forward();
    void traverse_backward();

};

#endif
