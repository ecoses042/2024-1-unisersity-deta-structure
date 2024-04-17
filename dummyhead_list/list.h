#pragma once

#include <iostream>
#include <assert.h>

using namespace std;
typedef int elemtype;

class list{
    public:
        list();
        ~list();
        void insert(const elemtype& elem);
        bool first(elemtype& elem);
        bool next(elemtype& elem);
        void remove(elemtype& elem);
    private:
        struct Node;
        typedef Node* link;
        struct Node{
            elemtype elem;
            link next;
        };
        link head;
        link tail;
        link current;
};