#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <assert.h>
using namespace std;

typedef int elementtype;
const int maxlistsize = 100;

class list{
    public:
        list();
        void insert(elementtype element);
        bool first(elementtype& element);
        bool next(elementtype& element);
        bool remove();
    private:
        struct Node;
        typedef Node *Link;
        struct Node{
            elementtype elem;
            Link next;
        };
        Link head;
        Link tail;
        Link current;
};


#endif