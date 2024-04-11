#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <assert.h>
using namespace std;
typedef int stack_type;
const int max_stack_size = 1000;

class stack{
    public:
        stack();
        ~stack();
        void push(const stack_type& value);
        stack_type pop();
        stack_type top();
    private:
        stack_type data[max_stack_size];
        int top;
};

#endif