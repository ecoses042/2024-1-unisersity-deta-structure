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
    table <int,int> mytable1;
    for (int i = 1; i <= 7; i++)
    {
        mytable1.insert(i,i);
    }
    mytable1.dump();
    mytable1.deletekey(1);
    mytable1.deletekey(2);
    mytable1.insert(1,1);
    mytable1.dump();

    table <int, Cphone> mytable2;
    mytable2.insert(1,Cphone("Minsoo1",1));
    mytable2.insert(2, Cphone("Minsoo2",2));
    mytable2.insert(3, Cphone("Minsoo3",3));
    mytable2.dump();
    
    table <int, Cphone> mytable3;
    mytable3.insert(strtoint("a"), Cphone("apple",1));
    mytable3.insert(strtoint("b"), Cphone("banana",2));
    mytable3.insert(strtoint("c"), Cphone("cherry",3));
    mytable3.insert(strtoint("d"), Cphone("durian",4));
    Cphone find;
    mytable3.lookup(strtoint("a"),find);
    cout << find << endl;
    cout << "20211530 Minsoo Song" << endl;
}