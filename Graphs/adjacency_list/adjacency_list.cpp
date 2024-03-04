#include <iostream>
#include <vector>
#include "adjacency_list.h"


// default constructor
AdjacencyList::AdjacencyList(){}


// parameterised constructor
AdjacencyList::AdjacencyList(int size)
{
    this->size = size;
    list = new Node* [size];

    for(int i=0; i<size; i++)
    {
        list[i] = nullptr;
    }
}


// destructor
AdjacencyList::~AdjacencyList()
{
    // delete linked list pointer in each array element
    for(int i=0; i<size; i++)
    {
        if(list[i]!=nullptr)
        {
            Node* temp = list[i];
            while(list[i]!=nullptr)
            {
                list[i] = temp->nextptr;
                // delete each node in the list till bead points to nullptr
                delete temp;
            }
        }
    }
    // lastly delete the entire array of pointers
    delete[] list;
}


// to add edges for both vertices
void AdjacencyList::add_edge(int vertex_1, int vertex_2)
{
    add_node(vertex_1, vertex_2);
    add_node(vertex_2, vertex_1);
}


void AdjacencyList::add_node(int vertex_1, int vertex_2)
{
    // update vertex 1 edges with first if list is empty
    if(list[vertex_1]==nullptr)
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
void AdjacencyList::remove_edge(int vertex_1, int vertex_2)
{
    delete_node(vertex_1, vertex_2);
    delete_node(vertex_2, vertex_1);
}


// remove node in list
void AdjacencyList::delete_node(int vertex_1, int vertex_2)
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

        while(currentptr!=nullptr)
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
bool AdjacencyList::check_edge(int vertex_1, int vertex_2)
{
    bool status = false;
    Node* temp = list[vertex_1];
    while(temp!=nullptr)
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
void AdjacencyList::find_adjacents(int vertex, std::vector<int> &adj)
{
    Node* currentptr = list[vertex];
    while(currentptr!=nullptr)
    {
        adj.push_back(currentptr->vertex);
        currentptr = currentptr->nextptr;
    }
}


// to display graph as array of linked list
void AdjacencyList::print_list()
{
    // iterate through each linked list and print
    for(int i=0; i<size; i++)
    {
        traverse_graph(i);
    }
    std::cout<<std::endl;
}


// utility function to print all nodes in a linked list
void AdjacencyList::traverse_graph(int index)
{
    if(list[index]!=nullptr)
    {
        Node* next_nodeptr = list[index];
        while(next_nodeptr!=nullptr)
        {
            std::cout<<next_nodeptr->vertex<<"-->";
            next_nodeptr = next_nodeptr->nextptr;
        }

        // nextptr of last node, always nullptr
        std::cout<<"nullptr";
        std::cout<<std::endl;
    }

    // if list has no nodes at all then simply print null
    else
    {
        std::cout<<"nullptr"<<std::endl;
    }
}
