#include <iostream>
#include "hash_table.h"


// default constructor
HashTable::HashTable(){}


// parameterized constructor
HashTable::HashTable(int size)
{
    table_size = size;
    main_pointer = new Node* [table_size]; // we are dynamically creating an array of pointers

    for(int i=0; i<table_size; i++)
    {
        // each item in array is a pointer that point to pointers of type Node
        main_pointer[i] = nullptr;
    }
}


// destructor to deallocate the memory  -->> check this again
HashTable::~HashTable()
{
    // delete each node in each linked list
    for(int i=0; i<table_size; i++)
    {
        if(main_pointer[i]!=nullptr)
        {
            Node* temp = main_pointer[i];
            while(main_pointer[i]!=nullptr)
            {
                main_pointer[i] = temp->nextptr;
                delete temp;
            }
        }
    }
    // lastly delete the entire array of pointers
    delete [] main_pointer;
}


// hash function
int HashTable::hash_function(int key)
{
    int hash_value = key % table_size;
    return hash_value;
}


// to print hash table array only
void HashTable::print_table()
{
    for(int i=0; i<table_size; i++)
    {
        traverse_hash(i);
    }
}


// to insert a key-value pair at the head of the list O(1)
void HashTable::insert_key(int key, int value)
{
    int hash_value = hash_function(key);

    // if particular hash has no key-value node pair stored
    if(main_pointer[hash_value]==nullptr)
    {
        // pointer in hash table array for that hash points to a new Node
        main_pointer[hash_value] = new Node;

        // pointer at particular array index points to particular Node
        main_pointer[hash_value]->key = key;
        main_pointer[hash_value]->value = value;

    }

    // avoid collision by chaining, insert at the head of linked list
    else
    {
        // create new node and assign values
        Node* new_node = new Node;
        Node* next_nodeptr = main_pointer[hash_value];
        new_node->key = key;
        new_node->value = value;

        // insert new node at head and old head is next node
        new_node->nextptr = next_nodeptr;
        next_nodeptr->prevptr = new_node;
        main_pointer[hash_value] = new_node;

    }
}


// to search_key for key with value O(n/m +1) worst case
int HashTable::search_key(int key)
{
    int hash_value = hash_function(key);

    // if linked list in that particular hash is not empty
    if(main_pointer[hash_value]!=nullptr)
    {
        Node* next_nodeptr = main_pointer[hash_value];
        while(next_nodeptr!=nullptr)
        {
            if(next_nodeptr->key==key)
            {
                // return value stored by that key
                return next_nodeptr->value;
            }
            next_nodeptr = next_nodeptr->nextptr;
        }

        // key not found for the hassh given
        std::cout<<"Key doesn't exist\n";
        return false;
    }

    // linked list is empty so no key stored
    else
    {
        std::cout<<"Key doesn't exist\n";
        return false;
    }

}


// delete a particular key O(n/m +1) is need to traverse
void HashTable::delete_key(int key)
{
    int hash_value = hash_function(key);
    bool key_present = false;

    if(main_pointer[hash_value]!=nullptr)
    {
        Node* current_nodeptr = main_pointer[hash_value];
        Node* prevptr = nullptr;

        // traverse list to locate key and delete node
        while(current_nodeptr!=nullptr)
        {
            prevptr = current_nodeptr->prevptr;

            if(current_nodeptr->key==key)
            {
                prevptr->nextptr = current_nodeptr->nextptr;
                current_nodeptr->nextptr->prevptr = prevptr;
                delete current_nodeptr;

                std::cout<<"Key "<<key<<" deleted.\n";
                key_present = true;
                break;
            }

            // shift to next node
            current_nodeptr = current_nodeptr->nextptr;
        }

        if(!key_present)
        {
            std::cout<<"Key "<<key<<" not present\n";
        }

    }

    // if linked list in that particular hash is empty
    else
    {
        std::cout<<"Key "<<key<<" not present\n";
    }

}


// to traverse the whole linked list in a particular hash for debugging only
void HashTable::traverse_hash(int index)
{
    if(main_pointer[index]!=nullptr)
    {
        Node* next_nodeptr = main_pointer[index];
        while(next_nodeptr!=nullptr)
        {
            std::cout<<next_nodeptr->value<<"-->";
            next_nodeptr = next_nodeptr->nextptr;
        }

        // nextptr of last node, always nullptr
        std::cout<<"nullptr"<<std::endl;
    }

    else
    {
        std::cout<<"nullptr"<<std::endl;
    }
}
