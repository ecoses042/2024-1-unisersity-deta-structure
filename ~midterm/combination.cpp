#include <iostream>
//20211530 송민수 자료구조
using namespace std;
int find_combination(int n, int k);

int runtime = 0;
int main()
{
    int n,k;

    cout << "20211530 Minsoo song" << endl;
    cout << "Enter n and k: ";
    cin >> n >> k;
    int combination = find_combination(n,k);
    cout << "this is combination possible: "<< combination << endl;
    cout << "number of function calls: "<< runtime << endl;
}

int find_combination(int n, int k)
{
    runtime++;
    if (k == 1)
        return n;
    else if (k == n)
        return 1; 
    else
        return find_combination(n-1,k-1) + find_combination(n -1, k);
}