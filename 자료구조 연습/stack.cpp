#include <iostream>
#include <assert.h>

using namespace std;
const int maxsize = 10;

class stack{
    public:
        stack();
        void push(const int& value);
        int pop();
        int top();
        bool isempty();
        bool isfull();
    private:
        int content[maxsize];
        int top_index;
};

int main()
{
    stack a;
    cout << "enter a push stack value" << endl;
    for (int i = 0; i < maxsize; i++)
    {
        int value;
        cin >> value;
        a.push(value);
    }
    cout << "poping stack" << endl;
    for (int i = 0; i < maxsize; i++)
    {
        cout << a.pop() << endl;
    }
    return 0;
}   


stack::stack()
{
    top_index = -1;
}

void stack::push(const int& value)
{
    if (isfull())
    {
        return ;
    }
    else
    {
        top_index++;
        content[top_index]= value;
    }
}

int stack::pop()
{
    if (isempty())
    {
        return -1;
    }
    else
    {
        return content[top_index--];
    }
}

int stack::top()
{
    if (isempty())
    {
        return -1;
    }
    else
    {
        int return_index = top_index;
        top_index -= 1;
        return content[return_index];
    }
}

bool stack::isempty()
{
    return top_index == -1;
}

bool stack::isfull()
{
    return top_index == maxsize - 1;
}