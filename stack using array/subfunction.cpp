#include "array_stack.h"
template<typename stack_type>
stack<stack_type>::stack()
{
    top_index = -1;
}
template<typename stack_type>
void stack<stack_type>::push(const stack_type& value)
{
    ++top_index;
    if (top_index > max_stack_size)
        return ;
    data[top_index] = value;
}
template<typename stack_type>
stack_type stack<stack_type>::pop()
{
    assert(top_index < max_stack_size && top_index > -1);
    int return_index = top_index;
    --top_index;
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

template<typename stack_type>
bool stack<stack_type>::operation(char stack_operator)
{
    stack_type a = pop();
    stack_type b = pop();
    if (a == NULL || b == NULL)
    {
        return false;
    }
    switch (stack_operator)
    {
        case '+':
        {
            push(a + b);
            break;
        }
        case '-':
        {
            push(a - b);
            break;
        }
        case '*':
        {
            push(a * b);
            break;
        }
        case '/':
        {
            push(a / b);
            break;
        }
    }
    return true;
}