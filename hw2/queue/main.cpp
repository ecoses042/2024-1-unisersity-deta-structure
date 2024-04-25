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
    while (q.isempty())
    {
        cout << q.dequeue();
    }
    return 0;
}