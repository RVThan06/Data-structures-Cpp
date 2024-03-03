#include "node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{

private:
    Node* headptr = nullptr;

public:
    // default constructor
    LinkedList();

    // parameterized constructor
    LinkedList(int);

    // destructor
    ~LinkedList();

    // member functions
    void insert_front(int);
    void insert_end(int);
    void insert_node(int, int);
    void traverse_list(int, bool insert_node=false);
    void delete_front();
    void delete_node(int);
    void display_list();
};


#endif
