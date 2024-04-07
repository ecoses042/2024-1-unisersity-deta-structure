#include <iostream>

using namespace std;

int linear_search(int a[], int size, int item)
{
    if (size <= 0)
        return -1;
    if (a[size - 1] == item)
        return (size - 1);
    else
        return linear_search(a, size - 1, item); 
}

int binary_search(int a[], int first, int last, int item)
{
    if (first <= last)
        return -1;
    int mid = (first + last) / 2;
    if (a[mid] == item)
        return mid;
    else if (a[mid] < item)
        return (binary_search(a, mid + 1, last, item));
    else
        return (binary_search(a, first, mid - 1, item));
}

void selection_sort(int a[], int size)
{
    if (size == 1)
        return ;
    
}