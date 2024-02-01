/**
 * This program demonstrates the implementation of binary search tree
 * in c++. In this program in order traversal is the chosen mode of
 * traversal for tree nodes. However, preorder and postorder travesal
 * can also be implemeneted in future.
*/

#include <iostream>


// struct for each node
struct Node
{
    int value;
    Node* right = NULL;
    Node* left = NULL;
};


class BinarySearchTree
{
private:
    Node* root = NULL;

public:

    // default constructor
    BinarySearchTree(){}

    // parameterized constructor
    BinarySearchTree(int value)
    {
        // create root node
        root = new Node;
        root->value = value;
    }

    // desctructor -> to be built
    ~BinarySearchTree()
    {
        // post-order traversal to delete each node
        post_order_delete();

    }


    // insert node function
    Node* insert_node(int value, Node* node)
    {

        // when the left / right subtree points to NULL
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


    void insert(int value)
    {
        // pass the root not for first recursion
        root = insert_node(value, root);
    }


    void inorder_traversal(Node* node)
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


    void inorder()
    {
        inorder_traversal(root);
    }

    // post order traversal to delete left node, right, lastly root
    void postorder_traversal(Node* node)
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


    void post_order_delete()
    {
        postorder_traversal(root);
    }


    Node* delete_node(int value, Node* node)
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
            if(node->right==NULL && node->left==NULL)
            {
                delete node;
                return NULL;
            }

            // only right child
            else if(node->right!=NULL && node->left==NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // only left child
            else if(node->left!=NULL && node->right==NULL)
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


    void delete_n(int value)
    {
        root = delete_node(value, root);
    }


    //to find the samlled value in the left subtree
    Node* find_minimum(Node* node)
    {
        Node* prev_node= NULL;
        while(node!=NULL)
        {
            prev_node = node;
            node = node->left;
        }

        return prev_node;
    }

};



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
