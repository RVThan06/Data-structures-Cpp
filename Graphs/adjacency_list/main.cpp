#include <iostream>
#include <vector>


// singly linked list node
struct Node
{
    int vertex;
    Node* nextptr = NULL;
};


class AdjacencyList
{
private:
    int size;
    Node** list;

public:

    // default constructor
    AdjacencyList(){}

    // parameterised constructor
    AdjacencyList(int size)
    {
        this->size = size;
        list = new Node* [size];

        for(int i=0; i<size; i++)
        {
            list[i] = NULL;
        }
    }

    // destructor
    ~AdjacencyList()
    {
        // delete linked list pointer in each array element
        for(int i=0; i<size; i++)
        {
            if(list[i]!=NULL)
            {
                Node* temp = list[i];
                while(list[i]!=NULL)
                {
                    list[i] = temp->nextptr;
                    // delete each node in the list till bead points to NULL
                    delete temp;
                }
            }
        }
        // lastly delete the entire array of pointers
        delete[] list;
    }


    // to add edges for both vertices
    void add_edge(int vertex_1, int vertex_2)
    {
        add_node(vertex_1, vertex_2);
        add_node(vertex_2, vertex_1);
    }


    void add_node(int vertex_1, int vertex_2)
    {
        // update vertex 1 edges with first if list is empty
        if(list[vertex_1]==NULL)
        {
            list[vertex_1] = new Node;
            list[vertex_1]->vertex = vertex_2;
        }
        // add nodes if list is not empty
        else
        {
            Node* new_node = new Node;
            new_node->vertex = vertex_2;
            new_node->nextptr = list[vertex_1];
            list[vertex_1] = new_node;
        }
    }


    // remove edge for both vertices
    void remove_edge(int vertex_1, int vertex_2)
    {
        delete_node(vertex_1, vertex_2);
        delete_node(vertex_2, vertex_1);
    }


    // remove node in list
    void delete_node(int vertex_1, int vertex_2)
    {
        // if edge is the first node then simply delete and point head to next
        if(list[vertex_1]->vertex==vertex_2)
        {
            Node* temp = list[vertex_1];
            list[vertex_1] = temp->nextptr;
            delete temp;
        }
        // if edge is somewhere in the middle or end of the list
        else
        {
            Node* currentptr = list[vertex_1];
            Node* previousptr = currentptr;

            while(currentptr!=NULL)
            {
                if(currentptr->vertex==vertex_2)
                {
                    previousptr->nextptr = currentptr->nextptr;
                    delete currentptr;
                    break;
                }
                previousptr = currentptr;
                currentptr = currentptr->nextptr;
            }
        }
    }


    // to check if an edge exist between two given vertices
    bool check_edge(int vertex_1, int vertex_2)
    {
        bool status = false;
        Node* temp = list[vertex_1];
        while(temp!=NULL)
        {
            if(temp->vertex==vertex_2)
            {
                status = true;
                break;
            }
            temp = temp->nextptr;
        }
        return status;
    }


    // search for all adjacent vertices for a given vertex
    void find_adjacents(int vertex, std::vector<int> &adj)
    {
        Node* currentptr = list[vertex];
        while(currentptr!=NULL)
        {
            adj.push_back(currentptr->vertex);
            currentptr = currentptr->nextptr;
        }
    }


    // to display graph as array of linked list
    void print_list()
    {
        // iterate through each linked list and print
        for(int i=0; i<size; i++)
        {
            traverse_graph(i);
        }
        std::cout<<std::endl;
    }

    // utility function to print all nodes in a linked list
    void traverse_graph(int index)
    {
        if(list[index]!=NULL)
        {
            Node* next_nodeptr = list[index];
            while(next_nodeptr!=NULL)
            {
                std::cout<<next_nodeptr->vertex<<"-->";
                next_nodeptr = next_nodeptr->nextptr;
            }

            // nextptr of last node, always NULL
            std::cout<<"NULL";
            std::cout<<std::endl;
        }

        // if list has no nodes at all then simply print null
        else
        {
            std::cout<<"NULL"<<std::endl;
        }
    }
};


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
