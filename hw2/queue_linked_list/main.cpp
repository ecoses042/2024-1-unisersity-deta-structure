#include "queue.h"
int main()
{
    queue <CMyClass> q;
    int take = 1;
    while (take != 0)
    {
        cout << "enter number(0 to stop):" << endl;
        cin >> take;
        if (take == 0)
            break;
        CMyClass C(take);
        q.enqueue(C);
    }
    while (!q.isEmpty())
    {
        CMyClass C(q.dequeue());
        cout << C << endl;
    }
    cout << "20211530 Minsoo Song" << endl;
    return 0;
}