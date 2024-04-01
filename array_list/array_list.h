#ifndef  LIST_H
#define LIST_H

#include <iostream>
#include <assert.h>

typedef int elementtype;
const int maxlistsize = 100;

class list{
    public:
        list();
        void insert(const elementtype& element);
        bool first(elementtype element);
        bool next(elementtype element);
    private:
        elementtype listarray[maxlistsize];
        int numberOfelements;
        int currentPosistion;
};
#endif