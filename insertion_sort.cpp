#include <iostream>

using namespace std;
void insert_next(int array[], int size);
int main()
{
    int n;
    int *array;

    n = 0;
    cin >> n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    insert_next(array, n);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    delete [] array;
    return 0;
}

void insert_next(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = array[i];
        int start = i - 1;
        while (array[start] > current && start != -1)
        {
            array[start + 1] = array[start];
            start--;
        }
        array[start + 1] = current;
    }
}