/**
 * This program demonstrates max heap data structure
 * implementation in c++.
*/

#include <iostream>
#include <vector>
#include <cmath>


void heapify(int index, std::vector<int> &my_heap)
{
    // compare parent node with the child nodes till leaf
    int length = my_heap.size();
    int largest = index;
    int left_child = 2*index + 1;
    int right_child = 2*index + 2;


    if(right_child<length && my_heap[right_child]>my_heap[index])
    {
        largest = right_child;
    }

    if(left_child < length && my_heap[left_child] > my_heap[largest])
    {
        largest = left_child;
    }

    if(largest!=index)
    {
        int temp = my_heap[index];
        my_heap[index] = my_heap[largest];
        my_heap[largest] = temp;

        // next recursion move to child node just swaped, so we go to lower nodes to heapify
        heapify(largest, my_heap);
    }
}


void build_heap(std::vector<int> &my_heap)
{
    // find the internal nodes(non-leaf nodes)
    int nodes = (std::floor(my_heap.size()/2) - 1);

    for(int i=nodes; i>=0; i--)
    {
        heapify(i, my_heap);
    }
}


void delete_node(int value, std::vector<int> &my_heap)
{
        int index;
        int last_index = my_heap.size()-1;
        for(int i=0; i<=last_index; i++)
        {
            if(value==my_heap[i])
            {
                index = i;
                break;
            }
        }
        // replace last item value with the value to be deleted
        my_heap.at(index) = my_heap.at(last_index);
        // remove last item
        my_heap.pop_back();
        heapify(index, my_heap);
}


void print_heap(std::vector<int> &my_heap)
{
    for(const int& num: my_heap)
    {
        std::cout<<num<<", ";
    }
    std::cout<<std::endl;
}



int main()
{
    // initialise vector
    std::vector<int> my_heap {33, 42, 10, 14, 19, 27, 44, 26, 31};

    // build heap using current vector
    build_heap(my_heap);

    // print heap
    print_heap(my_heap);

    // delete node and print heap
    delete_node(44, my_heap);
    print_heap(my_heap);

    // delete another node
    delete_node(33, my_heap);
    print_heap(my_heap);


    return 0;
}
