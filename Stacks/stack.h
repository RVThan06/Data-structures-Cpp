#ifndef STACK_H
#define STACK_H


class stack
{

private:
    int size;
    int top = -1;
    int* arr = nullptr;

public:

    // default constructor
    stack();

    // parameterized constructor
    stack(int);

    // destructor
    ~stack();

    // member functions
    bool is_not_empty();
    void push(int);
    int pop();
    void peak();
    void display_stack();

};


#endif
