#include <vector>
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H



class AdjacencyMatrix
{
private:
    int vertices;
    bool** matrix = nullptr;

public:

    // default constructor
    AdjacencyMatrix();

    // parameterized constructor
    AdjacencyMatrix(int);

    // destructor
    ~AdjacencyMatrix();

    // member functiona
    void add_edge(int, int);
    void remove_edge(int, int);
    bool check_edge(int, int);
    void find_adjacents(std::vector<int>&, int);
    void print_matrix();
};


#endif
