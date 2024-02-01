/*

This program contains a hash table built with chaining,
thus each hash table element stores a pointer that acts more
like a head pointer that points to a linked list.

If collision happens the new key value pair will be added to the head
of the linked list thus insertion happens in the front at O(1).

However, in worst case deletion and search will take O(n) if all
keys or most keys were to collide over and over due to having
same hash value.

But with a good hash function with perfecct uniform disgtribution,
the deletion and search operation will take O(1) in most case.

*/

#include <iostream>


// doubly linked list node
struct Node
{
    int key;
    int value;
    Node* prevptr = NULL;
    Node* nextptr = NULL;
};


class HashTable
{
private:
    int table_size;  // hash table size
    Node** main_pointer; // pointer to pointer of type Node

public:

    // default constructor
    HashTable(){}

    // parameterized constructor
    HashTable(int size)
    {
        table_size = size;
        main_pointer = new Node* [table_size]; // we are dynamically creating an array of pointers

        for(int i=0; i<table_size; i++)
        {
            // each item in array is a pointer that point to pointers of type Node
            main_pointer[i] = NULL;
        }
    }

    // destructor to deallocate the memory  -->> check this again
    ~HashTable()
    {
        // delete each node in each linked list
        for(int i=0; i<table_size; i++)
        {
            if(main_pointer[i]!=NULL)
            {
                Node* temp = main_pointer[i];
                while(main_pointer[i]!=NULL)
                {
                    main_pointer[i] = temp->nextptr;
                    delete temp;
                }
            }
        }
        // lastly delete the entire array of pointers
        delete[] main_pointer;
    }


    // hash function
    int hash_function(int key)
    {
        int hash_value = key % table_size;
        return hash_value;
    }


    // to print hash table array only
    void print_table()
    {
        for(int i=0; i<table_size; i++)
        {
            traverse_hash(i);
        }
    }

    // to insert a key-value pair at the head of the list O(1)
    void insert_key(int key, int value)
    {
        int hash_value = hash_function(key);

        // if particular hash has no key-value node pair stored
        if(main_pointer[hash_value]==NULL)
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
    int search_key(int key)
    {
        int hash_value = hash_function(key);

        // if linked list in that particular hash is not empty
        if(main_pointer[hash_value]!=NULL)
        {
            Node* next_nodeptr = main_pointer[hash_value];
            while(next_nodeptr!=NULL)
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
    void delete_key(int key)
    {
        int hash_value = hash_function(key);
        bool key_present = false;

        if(main_pointer[hash_value]!=NULL)
        {
            Node* current_nodeptr = main_pointer[hash_value];
            Node* prevptr = NULL;

            // traverse list to locate key and delete node
            while(current_nodeptr!=NULL)
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
    void traverse_hash(int index)
    {
        if(main_pointer[index]!=NULL)
        {
            Node* next_nodeptr = main_pointer[index];
            while(next_nodeptr!=NULL)
            {
                std::cout<<next_nodeptr->value<<"-->";
                next_nodeptr = next_nodeptr->nextptr;
            }

            // nextptr of last node, always NULL
            std::cout<<"NULL"<<std::endl;
        }

        else
        {
            std::cout<<"NULL"<<std::endl;
        }
    }
};



int main()
{
    // 1. initialise hash table
    HashTable my_table(10);

    // 2. insert new key-value pairs
    my_table.insert_key(100, 2);
    my_table.insert_key(200, 3);
    my_table.insert_key(300, 4);

    // 3. print the table after insertion
    my_table.print_table();
    std::cout<<std::endl;

    // 4. search for keys and delete keys
    std::cout<<"Value at key 100: "<<my_table.search_key(100)<<std::endl;
    my_table.delete_key(200);
    my_table.delete_key(500);

    // 5. insert new keys
    my_table.insert_key(211, 3);
    my_table.insert_key(236, 2);
    my_table.insert_key(243, 8);
    my_table.insert_key(254, 33);
    my_table.insert_key(259, 7);
    my_table.insert_key(258, 5);


    // 6. to print entire hash table after inserting new keys
    std::cout<<std::endl;
    my_table.print_table();

    return 0;
}
