#include "stack.h"

template<typename stack_type>
stack<stack_type>::stack()
{
    head = NULL;
    tail = NULL;
}

template<typename stack_type>
void stack<stack_type>::push(const stack_type& value)
{
    l_stack addednode = new l_stack;
    assert(addednode);
    addednode->data = value;
    if (head == NULL)
    {
        head = addednode;
        tail = addednode;
    }
    addednode->next = head;
    head = addednode;
}

template<typename stack_type>
stack_type stack<stack_type>::pop()
{
    link removenode(head);
    assert(removenode);
    head = removenode->next;
    return (removenode->element);
}

template<typename stack_type>
stack_type stack<stack_type>::top()
{
    assert(head);
    return (head->element);
}

template<typename stack_type>
bool stack<stack_type>::isempty()
{
    return (bool(head));
}

