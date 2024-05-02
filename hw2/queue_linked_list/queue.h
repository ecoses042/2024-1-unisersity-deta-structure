#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class CMyClass{
    public:
        CMyClass();
        CMyClass(int n);
        ~CMyClass();
        int get_m_nID();
        friend ostream& operator<<(ostream& os, const CMyClass& first);
        //연산사 오버로딩 사용하여서 m_nID를 비교할 수 있도록 코딩
    private:
        int m_nID;
};

CMyClass::CMyClass()
{
    m_nID = 0;
}
CMyClass::CMyClass(int n)
{
    m_nID = n;
}

CMyClass::~CMyClass()
{

}

int CMyClass::get_m_nID()
{
    return m_nID;
}

ostream& operator<<(ostream& os, const CMyClass& first)
{
    os << first.m_nID;
    return os;
}
template <class queueelemtype>
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

template <class queueelemtype>
queue<queueelemtype>::queue()
{
    nodeptr f = NULL;
    nodeptr r = NULL;
}

template <class queueelemtype>
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

template <class queueelemtype>
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

template <class queueelemtype>
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

template <class queueelemtype>
queueelemtype queue<queueelemtype>::front()
{
    assert(f);
    return f->elem;
}

template <class queueelemtype>
bool queue<queueelemtype>::isEmpty()
{
    return bool(f == 0);
}