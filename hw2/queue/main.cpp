#include "queue.h"

int main()
{
    queue <char> q;
    char a;
    char b;

    cout << "enter a and b" << endl;
    cin >> a;
    cin >> b;
    q.enqueue(a);
    q.enqueue(b);
    while (!q.isempty())
    {
        char temp = q.dequeue();
        cout << temp << endl;
    }
    return 0;
}