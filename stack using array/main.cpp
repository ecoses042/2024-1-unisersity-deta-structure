#include "array_stack.h"

int main()
{
    stack<int> t;
    //i declaration

    cout << "enter items to add to stack, add 0 to stop";
    cin >> i;
    while (i!= 0)
    {
        t.push(i);
        cin >> i;
    }
    cout << "enter 1 to pop 2 to top and 0 to stop";
    cin >> i;
    while (i != 0)
    {
        switch(i)
        {
            case 1:
                cout << t.pop() << endl;
                break;
            case 2:
                cout << t.top() << endl;
                break;
            case 0:
                break;
            default:
                cout << "invalid input" << endl;
                break;
        }
    }
    return 0;
} 