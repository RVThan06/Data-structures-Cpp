#include <iostream>
#include "binary_tree.h"



// default constructor
BinarySearchTree::BinarySearchTree(){}


// parameterized constructor
BinarySearchTree::BinarySearchTree(int value)
{
    // create root node
    root = new Node;
    root->value = value;
}


// desctructor -> to be built
BinarySearchTree::~BinarySearchTree()
{
    // post-order traversal to delete each node
    post_order_delete();

}


// insert node function
Node* BinarySearchTree::insert_node(int value, Node* node)
{

    // when the left / right subtree points to nullptr
    if(!node)
    {
        // create a new node dynamically
        Node* new_node = new Node;
        new_node->value = value;
        return new_node;
    }

    else if(value < node->value)
    {
        node->left = insert_node(value, node->left);
        return node;
    }

    else if(value >= node->value)
    {
        node->right = insert_node(value, node->right);
        return node;
    }

}


void BinarySearchTree::insert(int value)
{
    // pass the root not for first recursion
    root = insert_node(value, root);
}


void BinarySearchTree::inorder_traversal(Node* node)
{
    if(node->left)
    {
        inorder_traversal(node->left);
    }
    std::cout<<node->value<<"-->";
    if(node->right)
    {
        inorder_traversal(node->right);
    }
}


void BinarySearchTree::inorder()
{
    inorder_traversal(root);
}


// post order traversal to delete left node, right, lastly root
void BinarySearchTree::postorder_traversal(Node* node)
{
    if(node->left)
    {
        postorder_traversal(node->left);
    }

    if(node->right)
    {
        postorder_traversal(node->right);
    }

    if(node)
    {   // std::cout<<node->value<<"-->";
        delete node;
    }
}


void BinarySearchTree::post_order_delete()
{
    postorder_traversal(root);
}


Node* BinarySearchTree::delete_node(int value, Node* node)
{
    if(value < node->value)
    {
        node->left = delete_node(value, node->left);
    }

    else if(value > node->value)
    {
        node->right = delete_node(value, node->right);
    }

    else if(value==node->value)
    {
        // if not is leaf node
        if(node->right==nullptr && node->left==nullptr)
        {
            delete node;
            return nullptr;
        }

        // only right child
        else if(node->right!=nullptr && node->left==nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // only left child
        else if(node->left!=nullptr && node->right==nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // if node has two children
        else
        {
            // find smallest node in right subtree
            Node* del_node = find_minimum(node->right);
            // copy that value to target node
            node->value = del_node->value;
            // delete the duplicate node which we copied value from
            node->right = delete_node(node->value, del_node);
        }
    }

    // return the node to be stored as child after deleting
    return node;
}


void BinarySearchTree::delete_n(int value)
{
    root = delete_node(value, root);
}


//to find the samlled value in the left subtree
Node* BinarySearchTree::find_minimum(Node* node)
{
    Node* prev_node= nullptr;
    while(node!=nullptr)
    {
        prev_node = node;
        node = node->left;
    }

    return prev_node;
}
