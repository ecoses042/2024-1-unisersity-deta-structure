#include "queue.h"
//20211530 송민수
int main()
{
    queue <char> q;
    char a;
    char b;

    cout << "enter a and b" << endl;
    cin >> a;
    cin >> b;
    q.enqueue('a');
    q.enqueue('b');
    while (!q.isempty())
    {
        char temp = q.dequeue();
        cout << temp << endl;
    }
    cout << "20211530 Minsoo Song" << endl;
    return 0;
}