#include "table.h"

int strtoint(string strName)
{
    int nSum = 0;
    for(int i = 0; i < strName.length(); i++)
    {
        nSum +=strName.at(i);
    }
    return nSum;
}


int main()
{
    table <int, Cphone> t;
    t.insert(strtoint("minsoo"), Cphone("Minsoo1",010621));
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
    cout << "search minsoo" << endl;
    Cphone C;
    t.lookup(strtoint("minsoo"),C);
    C.print();
}