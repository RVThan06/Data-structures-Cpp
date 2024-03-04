#include <iostream>
#include "adjacency_matrix.h"



int main()
{
    // 1. instatiate the matrix object
    AdjacencyMatrix matrix(5);

    // 2. add edges to the matrix
    matrix.add_edge(1, 2);
    matrix.add_edge(2, 3);
    matrix.add_edge(1, 4);
    matrix.add_edge(2, 4);
    matrix.add_edge(4, 3);

    // 3. print the matrix
    matrix.print_matrix();

    // 4. check if two vertices has edge
    std::cout<<"Edge between vertice 1 and 2: "<<matrix.check_edge(1, 2)<<std::endl;  // true
    std::cout<<"Edge between vertice 3 and 1: "<<matrix.check_edge(3, 1)<<std::endl;  // false

    // 5. find all adjacent to a vertice
    std::vector<int> my_adjacencies;
    matrix.find_adjacents(my_adjacencies, 2);
    std::cout<<"The adjacencies of vertex 2 are : ";
    for(int val: my_adjacencies)
    {
        std::cout<<val<<",";
    }

    std::cout<<std::endl;

    return 0;
}
