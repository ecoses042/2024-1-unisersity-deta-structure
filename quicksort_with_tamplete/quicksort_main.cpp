#include "qs.h"
template <class T>
void quick_sort(T a[], int first, int last);
template <class T>
int partition(T a[],int first, int last);
template <class T>
void swap(T a[], int i, int j);

int main()
{
    int int_tempID;
    string string_tempID;

    cstudent soongsil[10];
    for (int i = 0; i < 10 ; i++)
    {
        cout << "enter ID:";
        cin >> int_tempID;
        cout << "enter name:";
        cin >> string_tempID;
        soongsil[i] = cstudent(int_tempID, string_tempID);
    }
    quick_sort(soongsil, 0, 9);
    for (int i = 0; i < 10 ; i++)
    {
        cout << soongsil[i].get_Name() << endl;
        cout << soongsil[i].get_Id() << endl;
    }
    return 0;
}

template <class T>
void quick_sort(T a[], int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int pivot = partition(a, first, last);
    quick_sort(a, first, pivot - 1);
    quick_sort(a, pivot + 1, last);
    return ;
}

template <class T>
int partition(T a[],int first, int last)
{
    int lastsmall = first;
    for (int i = first + 1; i <= last; i++)
    {
        if (a[i] <= a[first])
        {
            lastsmall++;
            swap(a, i, lastsmall);
        }
    }
    swap(a, lastsmall, first);
    return lastsmall;
}

template <class T>
void swap(T a[], int i, int j)
{
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

bool operator <=(cstudent& first, cstudent& second)
{
    return (first.get_Id() <= second.get_Id());
}