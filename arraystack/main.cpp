#include "array_stack.h"

int main()
{
    stack<double>t;
    double op1,op2;
    char c;

    while ((c = cin.peek()) != '\n')
    {
        if (isdigit(c))
        {
            cin >> op1;
            t.push(op1);
        }
        else      {
            cin >> c;
            op2 = t.pop();
            op1 = t.pop();
            switch (c)
            {
                case '+':
                    t.push(op1 + op2);
                    break;
                case '-':
                    t.push(op1 - op2);
                    break;
                case '*':
                    t.push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0){
                        cout << "cannot divide by 0\n";
                        break;
                    }
                    t.push(op1 / op2);
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
            while ((c = cin.peek()) == ' ')
                cin.ignore(1,' ');
        }
    }
    cout << t.pop();
    return 0;
} 