#include "array_stack.h"

stack::stack()
{
    top = -1;
}

void stack::push(const stack_type& value)
{
    ++top;
    if (top > max_stack_size)
        return ;
    data[top] = value;

}

stack_type stack::pop()
{

}

stack_type stack::top()
{

}