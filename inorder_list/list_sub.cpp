#include "list.h"

list::list(){
    link first = new Node;
    assert(first);
    head = first;
    tail = first;
    current = first;
    first->next = NULL;
}

list::~list()
{
    link temp;
    while(head){
        temp=head;
        head=head->next;
        delete temp;
    }
}

void list::insert(const elemtype& elem)
{
    link added_Node = new Node;
    assert(added_Node);
    added_Node->elem = elem;
    link pred(head->next);
    if (pred == NULL || pred->elem >= elem)
    {
        added_Node->next = pred;
        head->next = added_Node;
    }
    else{
        while (pred->next != NULL && elem >= pred->next->elem)
        {
            pred = pred->next;
        }
        added_Node->next = pred->next;
        pred->next = added_Node;
    }
}


bool list::first(elemtype& elem)
{
    if (head->next == NULL)
        return false;
    else{
        elem = head->next->elem;
        current = head->next;
        return true;
    }
}

bool list::next(elemtype& elem)
{
    if (current->next == NULL)
        return false;
    else{
        current = current->next;
        elem = current->elem;
        return true;
    }
}