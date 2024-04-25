#pragma once

#include <iostream>
#include <assert.h>

template <typename queueelemtype>
class queue{
    public:
        queue();
        ~queue();
        void enqueue(const queueelemtype& elem);
        queueelemtype dequeue();
        queueelemtype front();
        bool isEmpty();
    private:
        struct node;
        typedef node* nodeptr;
        struct node{
            queueelemtype elem;
            nodeptr next;
        };
        nodeptr f;
        nodeptr r;
};

template <typename queueelemtype>
queue<queueelemtype>::queue()
{
    nodeptr f = NULL;
    nodeptr r = NULL;
}

template <typename queueelemtype>
queue<queueelemtype>::~queue()
{
    nodeptr delnode(f);
    while(f != NULL)
    {
        f = f->next;
        delete delnode;
        delnode = f;
    }
}

template <typename queueelemtype>
void queue<queueelemtype>::enqueue(const queueelemtype& elem)
{
    nodeptr newnode(new node);
    assert(newnode);
    newnode->elem = elem;
    newnode->next = NULL;

    if (f == NULL)
        f = newnode;
    else
        r->next = newnode;
    r = newnode;
}

template <typename queueelemtype>
queueelemtype queue<queueelemtype>::dequeue()
{
    assert(f);
    nodeptr temp(f);
    queueelemtype front(temp->elem);
    f = f->next;
    delete temp;
    if (f == NULL)
        r = NULL;
    return front;
}

template <typename queueelemtype>
queueelemtype queue<queueelemtype>::front()
{
    assert(f);
    return f->elem;
}

template <typename queueelemtype>
bool queue<queueelemtype>::isEmpty()
{
    return bool(f == 0);
}