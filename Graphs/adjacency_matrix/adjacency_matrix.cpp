#include <iostream>
#include <vector>
#include "adjacency_matrix.h"


// default constructor
AdjacencyMatrix::AdjacencyMatrix(){}


// parameterized constructor
AdjacencyMatrix::AdjacencyMatrix(int vertices)
{
    this->vertices = vertices;
    matrix = new bool* [vertices];
    for(int i=0; i<vertices; i++)
    {
        // each array element is a pointer pointing to an array of booleans
        matrix[i] = new bool [vertices];
        for(int j=0; j<vertices; j++)
        {
            matrix[i][j] = false;
        }
    }
}


// destructor
AdjacencyMatrix::~AdjacencyMatrix()
{
    for(int i=0; i<vertices; i++)
    {
        // delete each block of bool memeory
        delete[] matrix[i];
    }
    // delete the block of memory of boolean pointers
    delete[] matrix;
}


// add edges
void AdjacencyMatrix::add_edge(int row, int col)
{
    // set diagonal cells to true
    matrix[row][col]=true;
    matrix[col][row]=true;
}


// to remoce an edge
void AdjacencyMatrix::remove_edge(int row, int col)
{
    // set diagonal cells to false
    matrix[row][col]=false;
    matrix[col][row]=false;
}

// to check if two vertices have edge bwtween them
bool AdjacencyMatrix::check_edge(int row, int col)
{
    if(matrix[row][col]==true)
    {
        return true;
    }
    return false;

}

// find all vertices adjacent to given vertex
void AdjacencyMatrix::find_adjacents(std::vector<int> &adj, int row)
{
    for(int i=0; i<vertices; i++)
    {
        if(matrix[row][i]==true)
        {
            adj.push_back(i);
        }
    }
}


// to print out the whole matrix
void AdjacencyMatrix::print_matrix()
{
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
