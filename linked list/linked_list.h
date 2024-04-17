#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <assert.h>

using namespace std;
typedef int elementtype;

class list{
    public:
        list();
        ~list();
        void insert(const elementtype& element);
        bool first(elementtype& element);
        bool next(elementtype& element);
    private:
        struct Node;
        typedef Node *link;
        struct Node{
            elementtype elem;
            link next;
        };
        link head;
        link tail;
        link current;
};

#endif

template<typename stack_type>
stack<stack_type>::stack()
{
    head = NULL;
    tail = NULL;
}

template<typename stack_type>
stack<stack_type>::~stack()
{
    while(isempty())
        pop();
}
template<typename stack_type>
void stack<stack_type>::push(const stack_type& value)
{
    link addednode = new link;
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

