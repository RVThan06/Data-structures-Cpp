/**
 * This program demonstrates max heap data structure
 * implementation in c++.
*/

#include <iostream>
#include <vector>
#include <cmath>


class Heap
{
private:
    std::vector <int> heap;


public:

    // default constructor
    Heap(){}

    // parmeterized constructor
    Heap(int value)
    {
        heap.push_back(value);
    }

    // destructor
    ~Heap()
    {

    }

    // insert node into heap
    void insert(int value)
    {
        heap.push_back(value);
        double index = heap.size() - 1;
        heapify(index);
    }

    void delete_node(int value)
    {
        int index;
        int last_index = heap.size()-1;
        for(int i=0; i<=last_index; i++)
        {
            if(value==heap[i])
            {
                index = i;
                break;
            }
        }
        // replace last item value with the value to be deleted
        heap.at(index) = heap.at(heap.size()-1);
        // remove last item
        heap.pop_back();
        heapify(last_index-1);

    }

    void heapify(double index)
    {
        while(index!=0)
        {
            // index is of datatype double since ceil function needs decimal part
            int parent_index = std::ceil(index/2) - 1;
            if(heap.at(index)>heap.at(parent_index))
            {
                int temp = heap.at(index);
                heap.at(index) = heap.at(parent_index);
                heap.at(parent_index) = temp;
            }
            index = parent_index;
        }

    }

    void display_heap()
    {
        for(const int& num : heap)
        {
            std::cout<<num<<"-->";
        }
    }

};

int main()
{
    // initialise the heap object
    Heap my_heap(35);

    // insert multiple nodes
    int arr [9] = {33, 42, 10, 14, 19, 27, 44, 26, 31};
    for(const int& num: arr)
    {
        my_heap.insert(num);
    }

    // print the heap
    my_heap.display_heap();
    std::cout<<std::endl;

    // delete nodes and display
    my_heap.delete_node(14);
    my_heap.display_heap();
    std::cout<<std::endl;

    my_heap.delete_node(42);
    my_heap.display_heap();
    std::cout<<std::endl;

    my_heap.delete_node(44);
    my_heap.display_heap();

    return 0;
}
