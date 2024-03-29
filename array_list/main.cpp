
#include "array_list.h"
using namespace std;

int main()
{
    int temp;
    int listsize;
    list example;

    cout << "Enter the size of the list: ";
    cin >> listsize;
    cout << endl;
    for (int i = 0; i < listsize; i++)
    {
        cin >> temp;
        l_insert(temp);
    }
}