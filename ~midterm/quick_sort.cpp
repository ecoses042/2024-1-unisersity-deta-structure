#include <iostream>
//20211530 송민수 자료구조
using namespace std;
void quick_sort(int a[], int first, int last);
int partition(int a[],int lastsmall, int last);
void print_array(int a[], int size);

int main()
{
    int a[] = {4,5,6,76,87,98,3,41,234,5};

    cout << "20211530 Minsoo Song"  << endl;
    cout << "this is before quick sort:";
    print_array(a, sizeof(a)/sizeof(a[0]));
    quick_sort(a, 0, sizeof(a)/sizeof(a[0])-1);
    cout << "this is after quick sort:";
    print_array(a, sizeof(a)/sizeof(a[0]));
    return 0;
}

void quick_sort(int a[], int first, int last)
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

int partition(int a[],int lastsmall, int last)
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

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
