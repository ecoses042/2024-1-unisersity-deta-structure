#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
const int max_stack_size = 1000;

template<typename stack_type>
class stack{
    public:
        stack();
        void push(const stack_type& value);
        stack_type pop();
        stack_type top();
        bool isempty();
    private:
        stack_type data[max_stack_size];
        int top_index;
        
};
template<typename stack_type>
stack<stack_type>::stack()
{
    top_index = -1;
}
template<typename stack_type>
void stack<stack_type>::push(const stack_type& value)
{
    top_index = top_index + 1;
    assert(top_index < max_stack_size);
    data[top_index] = value;
}
template<typename stack_type>
stack_type stack<stack_type>::pop()
{
    cout << top_index << endl;
    assert(top_index >= 0);
    int return_index = top_index;
    top_index--;
    return data[return_index];
}
template<typename stack_type>

stack_type stack<stack_type>::top()
{
    assert(top_index < max_stack_size && top_index > -1);
    return data[top_index];
}

//true if empty, false if not
template<typename stack_type>
bool stack<stack_type>::isempty()
{
    return bool(top_index == -1);
}