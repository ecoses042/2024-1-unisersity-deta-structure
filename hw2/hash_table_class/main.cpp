#include "table.h"

int main()
{
    table <int, Cphone> t;
    t.insert(1, Cphone("Minsoo1",010621));
    t.insert(2, Cphone("Minsoo2",010622));
    t.insert(3, Cphone("Minsoo3",010623));
    t.insert(4, Cphone("Minsoo4",010624));
    t.insert(5, Cphone("Minsoo5",010625));
    t.insert(6, Cphone("Minsoo6",010626));
    t.insert(7, Cphone("Minsoo7",010627));
    t.insert(11,Cphone("Minsoo11",10628));
    t.dump();
    cout << "this is after deletion" << endl;
    t.deletekay(11);
    t.deletekay(2);
    t.insert(22,Cphone("Minsoo",22));
    t.dump();
}