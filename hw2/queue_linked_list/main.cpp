 #include "queue.h"

int main()
{
    queue <CMyClass> q;
    CMyClass C(40);
    q.enqueue(C);
    while (!q.isEmpty())
    {
        cout << q.dequeue() << endl;
    }
    return 0;
}