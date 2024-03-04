#ifndef NODE_H
#define NODE_H


struct Node
{
    int value;
    Node* prevptr = nullptr;
    Node* nextptr = nullptr;
};

#endif
