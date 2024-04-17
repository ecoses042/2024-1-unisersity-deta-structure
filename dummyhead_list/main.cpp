#include "list.h"
//20211530 송민수 자료구조
int main()
{
    list l;
    elemtype i;

    cout << "20211530 Minsoo Song" << endl;
    cout << "enter items to add to list, add 0 to stop:";
    cin >> i;
    while (i != 0)
    {
        l.insert(i);
        cin >> i;
    }
    cout << "enter item to remove from list, add 0 to stop:";
    elemtype test;
    cin >> test;
    while (test != 0)
    {
        l.remove(test);
        cin >> test;
    }
    l.remove(test);
    cout << "here are the items in the list.\n";
    elemtype elem;
    bool notempty(l.first(elem));
    
    while (notempty)
    {
        cout << elem << endl;
        notempty = l.next(elem);
    }
    return 0;
}