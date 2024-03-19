#include <iostream>

using namespace std;
int find_combination(int n, int k);

int count = 0;
int main()
{
    int n,k;

    cin >> n >> k;
    int combination = find_combination(n,k);
    cout << "this is combination possible: "<< combination << endl;
    cout << "number of function calls: "<< count << endl;
}

int find_combination(int n, int k)
{
    if (k == 1)
    {
        count++;
        return n;
    }
    else if (k == n)
    {
        count++;
        return 1;
    }   
    else
    {
        count++;
        return find_combination(n-1,k-1) + find_combination(n -1, k);
    }
}