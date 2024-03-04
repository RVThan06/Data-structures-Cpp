#include "node.h"
#ifndef HASH_TABLE_H
#define HASH_TABLE_H


class HashTable
{
private:
    int table_size;  // hash table size
    Node** main_pointer = nullptr; // pointer to pointer of type Node

public:

    // default constructor
    HashTable();

    // parameterized constructor
    HashTable(int);

    // destructor to deallocate the memory
    ~HashTable();

    // member functions
    int hash_function(int);
    void print_table();
    void insert_key(int,int);
    int search_key(int);
    void delete_key(int);
    void traverse_hash(int);
};


#endif
