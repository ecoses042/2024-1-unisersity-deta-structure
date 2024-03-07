#include <iostream>

using namespace std;
void select_next(int array[], int size);
int main()
{
    int n;
    int *array;

    n = 0;
    cin >> n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    select_next(array, n);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    delete [] array;
    return 0;
}

void select_next(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}