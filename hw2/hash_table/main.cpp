#include "table.h"

int main()
{
    table <int, int> t;
    t.insert(1, 1);
    t.insert(2, 2);
    t.insert(3, 3);
    t.insert(4, 4);
    t.insert(5, 5);
    t.insert(6, 6);
    t.insert(7, 7);
    t.dump();
}