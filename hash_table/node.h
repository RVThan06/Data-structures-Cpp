#ifndef NODE_H
#define NODE_H

// doubly linked list node
struct Node
{
    int key;
    int value;
    Node* prevptr = nullptr;
    Node* nextptr = nullptr;
};

#endif
