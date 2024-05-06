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
    table <int, int> t1;
    t1.insert(strtoint("a"), 1);
    t1.insert(strtoint("b"),2);
    t1.insert(strtoint("c"),3);
    
    t1.dump();
}