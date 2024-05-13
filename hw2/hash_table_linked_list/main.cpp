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
    table <int, Cphone> t1;
    t1.insert(1,Cphone("a",1));
    t1.insert(2,Cphone("b",2));
    t1.insert(3,Cphone("c",3));
    t1.dump();

    table <int, Cphone> t2;
    t2.insert(strtoint("a"), Cphone("a",1));
    t2.insert(strtoint("b"), Cphone("b",2));
    t2.insert(strtoint("c"), Cphone("c",3));
    Cphone look;
    t2.lookup(strtoint("a"), look);
    cout << look << endl;
    cout << "20211530 Minsoo Song"  << endl;
}