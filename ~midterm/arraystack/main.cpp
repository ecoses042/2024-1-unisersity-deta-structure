#include "array_stack.h"
//20211530 송민수 자료구조
int main()
{
    stack<double>t;
    double op1,op2;
    char c;

    cout << "20211530 Minsoo Song" << endl;
    while ((c = cin.peek()) != '\n')
    {
        while ((c = cin.peek()) == ' ')
                cin.ignore(1,' ');
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
        }
    }
    cout << t.pop();
    return 0;
} 