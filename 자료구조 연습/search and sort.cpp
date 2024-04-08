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
    int swap_index = -1;

    if (size == 0)
        return ;
    int max = a[size];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
            swap_index = i;
    }
    if (swap_index != -1)
    {
        a[swap_index] = a[size];
        a[size] = max;
    }
    selection_sort(a, size - 1);
}

void bubble_sort(int a[], int size, int current)
{
    if (size == 0)
        return ;
        for (int j = 0; j < size - current; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }   
        }
    bubble_sort(a, size -1, current + 1);
}


int partition(int a[], int lastsmall, int last)
{
    int pivot = a[lastsmall];
    int first = lastsmall;
    for (int i = lastsmall + 1; i <= last; i++)
    {
        if (a[i] < pivot)
        {
            swap(a[i], a[lastsmall + 1]);
            lastsmall++;
        }
    }
    swap(a[first],a[lastsmall]);
    return lastsmall;
}
void quick_sort(int a[], int first, int last)
{
    if (first >= last)
        return ;
    int pivot = partition(a, first, last);
    quick_sort(a, first, pivot - 1);
    quick_sort(a, pivot + 1, last);
    return ;
}

int main()
{
    int n;
    int *array;

    n = 0;
    cin >> n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    quick_sort(array, 0, n - 1);
    cout << "array after sorting: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    delete [] array;
    return 0;
}