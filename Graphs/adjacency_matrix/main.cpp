#include <iostream>
#include <vector>

class AdjacencyMatrix
{
private:
    int vertices;
    bool** matrix;

public:

    // default constructor
    AdjacencyMatrix(){}


    // parameterized constructor
    AdjacencyMatrix(int vertices)
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
    ~AdjacencyMatrix()
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
    void add_edge(int row, int col)
    {
        // set diagonal cells to true
        matrix[row][col]=true;
        matrix[col][row]=true;
    }


    // to remoce an edge
    void remove_edge(int row, int col)
    {
        // set diagonal cells to false
        matrix[row][col]=false;
        matrix[col][row]=false;
    }

    // to check if two vertices have edge bwtween them
    bool check_edge(int row, int col)
    {
        if(matrix[row][col]==true)
        {
            return true;
        }
        return false;

    }

    // find all vertices adjacent to given vertex
    void find_adjacents(std::vector<int> &adj, int row)
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
    void print_matrix()
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
};



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
