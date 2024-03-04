#include <vector>
#include "node.h"
#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H


class AdjacencyList
{
private:
    int size;
    Node** list = nullptr;

public:

    // default constructor
    AdjacencyList();

    // parameterised constructor
    AdjacencyList(int);

    // destructor
    ~AdjacencyList();

    // to add edges for both vertices
    void add_edge(int, int);
    void add_node(int, int);
    void remove_edge(int, int);
    void delete_node(int, int);
    bool check_edge(int , int);
    void find_adjacents(int , std::vector<int>&);
    void print_list();
    void traverse_graph(int);
};

#endif
