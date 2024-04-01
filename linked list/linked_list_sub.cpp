#include "linked_list.h"

list::list()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

//add a new node at the end of the list
void list::insert(const elementtype& element)
{
    link new_node = new Node;
    assert(new_node);
    if (head == NULL)
        head = new_node;
    else{
        tail->next = new_node;
    }
    tail = new_node;
    new_node->next = NULL;
    new_node->elem = element;
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
    assert(current);
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
    if (head == NULL)
        return false;
    else{ 
        while (head != NULL)
        {
            link temp = head;
            head = head->next;
            delete temp;
        }
    }
}