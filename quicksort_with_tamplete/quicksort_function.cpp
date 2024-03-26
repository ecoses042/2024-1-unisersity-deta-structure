#include "qs.h"

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
int partition(T a[],int lastsmall, int last)
{
    int pivot = a[lastsmall];
    int first = lastsmall;
    for (int i = lastsmall + 1; i <= last; i++)
    {
        if (a[i] <= pivot)
        {
            lastsmall++;
            swap(a[i], a[lastsmall]);
        }
    }
    swap(a[lastsmall], a[first]);
    return lastsmall;
}

template <class T>
void print_array(T a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
