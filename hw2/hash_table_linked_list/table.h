#pragma once

#include <iostream>
#include<assert.h>
using namespace std;
const int max_table_size = 11;

template <class tablekeytype, class tablevaluetype>
class table{
    public:
        table();
        void insert(const tablekeytype key, const tablevaluetype value);
        bool lookup(const tablekeytype& key,tablevaluetype& value);
        void deletekey(const tablekeytype & key);
        void dump();
    private:
        struct slot;
        typedef slot* link;
        int hash(const tablekeytype& key);
        struct slot{
            tablekeytype key;
            tablevaluetype value;
            link next;
        };
        link T[max_table_size];
        bool search(link & slotpointer, const tablekeytype & target);

};

template <class tablekeytype, class tablevaluetype>
table<tablekeytype, tablevaluetype>::table(){
    for (int i = 0; i < max_table_size;i++)
    {
        T[i] = NULL;
    }
}

template <class tablekeytype, class tablevaluetype>
void table<tablekeytype, tablevaluetype>::insert(const tablekeytype key, const tablevaluetype value)
{
    int pos(hash(key));
    link sp(T[pos]);
    if (!search(sp,key))
    {
        link addednode = new link;
        assert(addednode);
        addednode->key = key;
        addednode->value = value;
        addednode->next = T[pos];
        T[pos] = addednode;
    }
    else
    {
        sp->value = value;
    }
    //define new node
    //search for key in T[pos]
    //if not found, add new node to T[pos]
    //if found, update the value
}

template <class tablekeytype, class tablevaluetype>
bool table<tablekeytype, tablevaluetype>::search(link & slotpointer, const tablekeytype & target)
{
    for (; slotpointer; slotpointer = slotpointer->next)
    {
        if (slotpointer->key == target)
        {
            return true;
        }
    }
    return false;
}
template <class tablekeytype, class tablevaluetype>
void table<tablekeytype, tablevaluetype>::deletekey(const tablekeytype & key)
{
    int pos(hash(key));
    link dp(T[pos]);
    if (dp == NULL)
        return ;
    search(dp,key);
    if (dp->key == key)
    {
        T[pos] = dp->next;
        delete dp;
    }
    else
    {
        link p(T[pos]);
        for (;p;p = p->next)
        {
            if (p->next->key == key)
            {
                dp = p->next;
                p->next = dp->next;
                delete dp;
                break;
            }
        }
    }
    //two situations
    //move head pointer
    //edit between nodes

}

template <class tablekeytype, class tablevaluetype>
bool table<tablekeytype, tablevaluetype>::lookup(const tablekeytype& key, tablevaluetype& value){
    int pos = hash(key);
    link sp(T[pos]);
    if (search(sp,key))
    {
        for (;sp;sp = sp->next)
        {
            if (sp->key == key)
            {
                value = sp->value;
                return true;
            }
        }
    }
    else
        return false;
}


template <class tablekeytype, class tablevaluetype>
int table<tablekeytype, tablevaluetype>::hash(const tablekeytype& key){
    return key % max_table_size;
}


void dump(){
    for (int i = 0; i < max_table_size; i++)
    {
        slot sp(T[i]);
        for (;sp;sp = sp->next)
        {
            cout << "node " << i << "\t";
            cout << "key:";
            cout << sp->key << "\t";
            cout << "value:";
            cout << sp->value << "\t";
            cout << endl;
        }
    }
}