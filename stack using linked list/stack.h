#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

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
        typedef struct *link;
        struct l_stack{
            stack_type element;
            link next;
        };
        link head;
        link tail;
};
