#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10;
int main()
{
    int n, k, a, c = 0;
    cin >> n >> k;
    k = 5 - k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= k)
            c++;
    }
    cout << c / 3 << endl;
    return 0;
}