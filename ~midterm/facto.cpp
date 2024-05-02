#include <iostream>

using namespace std;

long long fact(int n);

int main()
{
    int n;
    cin >> n;
    long long fact_of_n = fact(n);
    cout << fact_of_n << endl;
    return 0;
}

long long fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}