#include <iostream>
//20211530 송민수 자료구조
using namespace std;
void select_next(int array[], int size);
int main()
{
    int n;
    int *array;
    
    cout << "20211530 Minsoo Song" << endl;
    cout << "enter a size of the array: ";
    cin >> n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    select_next(array, n - 1);
    cout << "array after sorting: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    delete [] array;
    return 0;
}

void select_next(int array[], int size)
{
    if (size == 0)
        return ;
    int min_index = size;
    int min  = array[size];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min_index = i;
            min = array[i];
        }
    }
    int temp = array[size];
    array[size] = min;
    array[min_index] = temp;
    select_next(array, size - 1);
}