#include "array_list.h"

list::list()
{
    numberOfelements = 0;
    currentPosistion = -1;
}

void list::insert(elementtype element)
{
    assert(numberOfelements < maxlistsize);
    listarray[numberOfelements] = element;
    numberOfelements++;
}

bool list::first(elementtype element)
{
    if (numberOfelements == 0)
        return false;
    else{
        currentPosistion = 0;
        element = listarray[currentPosistion];
        return true;
    }
}

bool list::next(elementtype element)
{
    assert(currentPosistion >= 0);
    if (currentPosistion >= numberOfelements - 1)
        return false;
    else{
        currentPosistion++;
        element = listarray[currentPosistion];
        return true;
    }
    
}