#include "list.h"

int main()
{
    list l;
    elemtype i;
    cout << "enter items to add to list, add 0 to stop:";
    cin >> i;
    while (i != 0)
    {
        l.insert(i);
        cin >> i;
    }
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