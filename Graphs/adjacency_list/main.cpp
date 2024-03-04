#include <iostream>
#include <vector>
#include "adjacency_list.h"



// main code implementation
int main()
{
    // 1. instantiate graph object
    AdjacencyList graph(5);

    // 2. add edges to the matrix
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 4);
    graph.add_edge(4, 3);

    // 3. print graph upon adding edges
    graph.print_list();

    // 4. remove edges and display graph
    graph.remove_edge(1,2);
    graph.print_list();

    // 5. check if edge is present
    std::cout<<"Edge between vertex 2 ad 3 exist: "<<graph.check_edge(3, 2)<<"\n";
    std::cout<<"Edge between vertex 0 ad 4 exist: "<<graph.check_edge(0, 4)<<"\n\n";

    // 6. to find all adjacencies with a given vertex
    std::vector<int> my_adjacencies;
    graph.find_adjacents(4, my_adjacencies);
    std::cout<<"The adjacencies of vertex 4 are : ";
    for(int val: my_adjacencies)
    {
        std::cout<<val<<",";
    }

    std::cout<<std::endl;

    return 0;
}
