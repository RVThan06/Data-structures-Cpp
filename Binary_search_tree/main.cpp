/**
 * This program demonstrates the implementation of binary search tree
 * in c++. In this program in order traversal is the chosen mode of
 * traversal for tree nodes. However, preorder and postorder travesal
 * can also be implemeneted in future.
*/

#include <iostream>
#include "binary_tree.h"


int main()
{

    // 1. instantiate binary search tree object
    BinarySearchTree my_tree(12);

    // 2. insert nodes into the tree
    my_tree.insert(13);
    my_tree.insert(7);
    my_tree.insert(10);
    my_tree.insert(16);
    my_tree.insert(5);
    my_tree.insert(4);
    my_tree.insert(1);
    my_tree.insert(20);
    my_tree.insert(6);

    // 3. print the tree by in order traversal
    my_tree.inorder();
    std::cout<<std::endl;

    // 4. delete a node with two children
    my_tree.delete_n(5);
    my_tree.delete_n(20);

    // 5. print the updated binary search tree
    my_tree.inorder();
    std::cout<<"\n";


    return 0;
}
