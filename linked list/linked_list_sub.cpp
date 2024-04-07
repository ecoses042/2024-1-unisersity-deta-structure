#include "linked_list.h"

list::list()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
/*void list::insert(elementtype element)
{
    Link addedNode = new Node;
    addedNode->elem = element;
    if (head == NULL)
        head = addedNode;
    else
        tail->next = addedNode;
    tail = addedNode;
    addedNode->next = NULL;
}*/

void list::insert(elementtype element)
{
    Link addedNode = new Node;
    addedNode->elem = element;
    addedNode->next = head;
    head = addedNode;
    if (tail == NULL)
        tail = addedNode;
        
}


bool list::first(elementtype& element)
{
    if (head == NULL)
        return false;
    else{
        element = head->elem;
        current = head;
        return true;
    }
}

bool list::next(elementtype& element)
{
    if (current->next == NULL)
        return false;
    else{
        current = current->next;
        element = current->elem;
        return true;
    }
}

bool list::remove()
{
    Link temp;
    if (head == NULL)
        return true;
    while (head->next != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    delete temp;
    return true;
}