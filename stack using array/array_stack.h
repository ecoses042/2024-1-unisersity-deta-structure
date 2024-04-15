#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <assert.h>
using namespace std;
const int max_stack_size = 1000;

template<typename stack_type>
class stack{
    public:
        stack();
        ~stack();
        void push(const stack_type& value);
        stack_type pop();
        stack_type top();
        bool isempty();
        bool operation(char stack_operator);
    private:
        stack_type data[max_stack_size];
        int top_index;
};

#endif