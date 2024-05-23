#pragma once

#include "bt.h"

template <class btelementtype>
class bst: public BinaryTree <btelementtype>{
    public:
        bst();
        virtual void insert(const btelementtype& d);
        virtual BinaryTree<btelementtype> * retrieve(const btelementtype& d);
    private:
        using BinaryTree<btelementtype>::nulltree;
        using BinaryTree<btelementtype>::data;
        using BinaryTree<btelementtype>::lefttree;
        using BinaryTree<btelementtype>::righttree;
};

template <class btelementtype>
bst<btelementtype>::bst():BinaryTree<btelementtype>(){
    nulltree = true;
    lefttree = 0;
    righttree = 0;
}

template <class btelementtype>
void 
bst<btelementtype>::insert(const btelementtype& d){
    if (nulltree)
    {
        nulltree = false;
        lefttree = new bst;
        righttree = new bst;
        data = d;
    }
    else if (d == data)
        data = d;
    else if (d < data)
        lefttree->insert(d);
    else
        righttree->insert(d);
}

template <class btelementtype>
BinaryTree<btelementtype> * 
bst<btelementtype>::retrieve(const btelementtype& d){
    if (nulltree || d == data)
        return this;
    else if (d < data)
        return ((bst<btelementtype>*)lefttree)->retrieve(d);
    else
        return ((bst<btelementtype>*)righttree)->retrieve(d);
}