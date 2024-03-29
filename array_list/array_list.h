#ifndef  LIST_H
#define LIST_H

#include <iostream>
#include <assert.h>

typedef int elementtype;
const int maxlistsize = 1000;

class list{
    public:
        list();
        void insert(elementtype element);
        bool first(elementtype element);
        bool next(elementtype element);
    private:
        int content[maxlistsize];
};
#endif