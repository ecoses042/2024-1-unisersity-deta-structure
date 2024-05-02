#include <iostream>

using namespace std;

void quick_sort(int a[], int first, int last);

int main()
{
    int array[] = {4,5,76,8,3,2,7,6,4,2};
    int n = sizeof(array)/sizeof(array[0]);

    cout << "Before sorting: ";
    for(int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    quick_sort(array,0,n);
    cout << "After sorting: ";
    for(int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(int a[], int first, int last)
{
    int pivot = a[first];
    int lastsmall = first;
    for (int i = first + 1; i < last; i++)
    {
        if (a[i] <= pivot)
        {
            lastsmall++;
            swap(a[i], a[lastsmall]);
            
        }
    }
    swap(a[first], a[lastsmall]);
    return lastsmall;
}
void quick_sort(int a[], int first, int last)
{
    if (first >= last)
        return;
    int pivot = partition(a, first, last);
    quick_sort(a, pivot +1, last);
    quick_sort(a, first, pivot - 1);
    return ;

}