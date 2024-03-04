#include "node.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H


class BinarySearchTree
{
private:
    Node* root = nullptr;

public:

    // default constructor
    BinarySearchTree();

    // parameterized constructor
    BinarySearchTree(int);

    // desctructor -> to be built
    ~BinarySearchTree();

    // member functions
    Node* insert_node(int, Node*);
    void insert(int);
    void inorder_traversal(Node*);
    void inorder();
    void postorder_traversal(Node*);
    void post_order_delete();
    Node* delete_node(int, Node*);
    void delete_n(int);
    Node* find_minimum(Node*);
};


#endif
