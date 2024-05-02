#include "linked_list.h"

//20211530 송민수 자료구조
int main()
{
    list l;
    elementtype i;

    cout << "20211530 Minsoo Song" << endl;
    cout << "enter items to add to list, add 0 to stop:";
    cin >> i;
    while (i != 0)
    {
        l.insert(i);
        cin >> i;
    }
    cout << "here are the items in the list.\n";
    elementtype elem;
    bool notempty(l.first(elem));
    while (notempty)
    {
        cout << elem << endl;
        notempty = l.next(elem);
    }
    return 0;
}