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
    new_node->elem = element;
    new_node->next = head;
    if (head)
        head->prev = new_node;
    new_node->prev = NULL;
    head = new_node;
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

void list::remove(elementtype& element)
{
    assert(head);
    link delNode, pred;
    for (pred = head; pred && pred->elem != element; pred = pred->next);
    if (pred && pred->elem == element)
    {
        delNode = pred;
        pred->prev->next = pred->next;
        pred->next->prev = pred->prev;
        delete delNode;
    }
}

bool list::prev(elementtype& element)
{
    assert(current);
    if (current->prev == NULL)
        return false;
    else{
        current = current->prev;
        element = current->elem;
        return true;
    }

}
list::~list()
{
        while (head != NULL)
        {
            link delNode = head;
            head = head->next;
            delete delNode;
        }
}