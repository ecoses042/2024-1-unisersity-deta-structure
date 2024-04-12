#pragma once

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