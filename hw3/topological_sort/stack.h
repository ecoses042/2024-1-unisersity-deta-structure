#pragma once

template<typename stack_type>
class stack{
    public:
        stack();
        ~stack();
        void push(const stack_type& value);
        stack_type pop();
        stack_type top();
        bool isEmpty();
        bool operation(char stack_operator);
    private:
        struct Node;
        typedef Node *link;
        struct Node{
            stack_type element;
            link next;
        };
        link head;
        link tail;
};

template<typename stack_type>
stack<stack_type>::stack()
{
    head = NULL;
    tail = NULL;
}

template<typename stack_type>
stack<stack_type>::~stack()
{
    while(!isEmpty())
        pop();
}
template<typename stack_type>
void stack<stack_type>::push(const stack_type& value)
{
    link addednode = new Node;
    assert(addednode);
    addednode->element = value;
    if (head == NULL)
    {
        tail = addednode;
    }
    addednode->next = head;
    head = addednode;
}

template<typename stack_type>
stack_type stack<stack_type>::pop()
{
    assert(head);
    link removenode(head);
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
bool stack<stack_type>::isEmpty()
{
    return (!bool(head));
}

