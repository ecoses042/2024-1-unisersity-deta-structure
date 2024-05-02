#include "table.h"

int main()
{
    table <char, int> t;
    t.insert('a', 1);
    t.insert('b', 2);
    t.insert('c', 3);
    char searchkey = 'a';
    int value = 0;
    t.lookup(searchkey,value);
    cout << value << endl;
}