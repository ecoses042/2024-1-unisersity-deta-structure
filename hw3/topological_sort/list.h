#pragma once
template <class listelemtype>
class listiter;

template <class listelemtype>
class list{
    public:
        list();
        ~list();
        virtual void insert(const listelemtype& element);
        friend class listiter <listelemtype>;
    protected:
        struct node;
        typedef node * link;
        struct node
        {
            listelemtype element;
            link next;
        };
        link head;
};

template <class listelemtype>
list<listelemtype>::list()
{
    head = 0;
}

template<class listelemtype>
list<listelemtype>::~list()
{
    link current = head;
    while(current!= 0)
    {
        link temp = current;
        current = current->next;
        delete temp;
    }
}

template <class listelemtype>
void list<listelemtype>::insert(const listelemtype& element)
{
    link addednode = new node;
    assert(addednode);
    addednode->element = element;
    addednode->next = head;
    head = addednode;
}


template <class listelemtype>
class listiter
{
    public:
        //function that takes a list and returns next element in the list.
        listiter(const list<listelemtype> & takelist, listelemtype endflag)
            :mylist(takelist), myendflag(endflag), iterptr(0){}
        //function used in listiter to point to next listelement
        virtual listelemtype operator++();
    protected:
        //list to bring element from
        const list<listelemtype>& mylist;
        //take link variable type from class list and use it to define listptr 
        //to be used in listiter class
        typename list<listelemtype>::link iterptr;
        listelemtype myendflag;
    private:
};


template<class listelemtype>
listelemtype 
listiter<listelemtype>::operator++()
{
    if (iterptr == 0)
    {
        iterptr = mylist.head;
    }
    else
        iterptr = iterptr->next;
    if (iterptr)
        return iterptr->element;
    else
        return myendflag;
}



