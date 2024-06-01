#pragma once

#include <iostream>
#include <assert.h>
//20211530 송민수
//declaration of class tree
using namespace std;
template <class btelementtype>
class BinaryTree{
    public:
        BinaryTree();
        bool isempty()const;
        btelementtype getData();
        void insert (const  btelementtype& element);
        BinaryTree* left();
        BinaryTree* right();
        void makeleft(BinaryTree* T);
        void makeright(BinaryTree* T);
    protected:
        bool nulltree;
        btelementtype data;
        BinaryTree* lefttree;
        BinaryTree* righttree;
    private:
        
};

template <class btelementtype>
BinaryTree<btelementtype>::BinaryTree(){
    nulltree = true;
    lefttree = 0;
    righttree = 0;
}

template <class btelementtype>
bool BinaryTree<btelementtype>::isempty() const{
    return nulltree;
}

template <class btelementtype>
btelementtype BinaryTree<btelementtype>::getData(){
    assert(!isempty());
    return data;
}

template <class btelementtype>
void BinaryTree<btelementtype>::insert(const btelementtype& element){
    data = element;
    if (nulltree)
    {
        nulltree = false;
        lefttree = new BinaryTree;
        righttree = new BinaryTree;
    }
}

template <class btelementtype>
BinaryTree<btelementtype>* BinaryTree<btelementtype>::left(){
    assert(!isempty());
    return lefttree;
}

template <class btelementtype>
BinaryTree<btelementtype>* BinaryTree<btelementtype>::right(){
    assert(!isempty());
    return righttree;
}

template <class btelementtype>
void BinaryTree<btelementtype>::makeleft(BinaryTree* T){
    assert(!isempty());
    assert(left()->isempty());
    //delete left();
    lefttree = T;
}

template <class btelementtype>
void BinaryTree<btelementtype>::makeright(BinaryTree* T){
    assert(!isempty());
    assert(right()->isempty());
    //delete right();
    righttree = T;
}