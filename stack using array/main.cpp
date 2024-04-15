#include "array_stack.h"

bool isoperator(char test)
{
    return test == '+' || test == '-' || test == '*' || test == '/';
}

int main()
{
    stack <double>t;
    char i;
    cout << "enter items to start calculation(enter 0 to stop): ";
    cin >> i;
    while (i != 0)
    {
        if (!isoperator(i))
            t.push(i);
        cin >> i;
    }
    return 0;
} 