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
#include "hash_table.h"



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
