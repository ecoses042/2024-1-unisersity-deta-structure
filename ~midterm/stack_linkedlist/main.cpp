#include "stack.h"

int main()
{
    stack<int> s;
    int i = -1;
    int mode;
    while (mode != 0)
    {
        cout << "1 for push, 2 for pop and 3 for top, 0 to stop:";
        cin >> mode;
        switch(mode)
        {
            case 1:
                cout << "Enter the element to be pushed:";
                cin >> i;
                s.push(i);
                break;
            case 2:
                cout << s.pop() << endl;
                break;
            case 3:
                cout << s.top() << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    return 0;
}