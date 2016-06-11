#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int zero, one;
    cin >> zero >> one;
    if (one < zero - 1 || one > 2 * (zero + 1))
        cout << "-1";
    else if (one == zero || zero == one + 1)
    {
        for (int i = 0; i < zero - 1; i++)
            cout << "01";
        if (one == zero)
            cout << "01";
        else
            cout << "0";
    }
    else if (zero < one && one <= zero * 2)
    {
        for (int i = 0; i < one - zero; i++)
            cout << "110";
        for (int i = 0; i < 2 * zero - one; i++)
            cout << "10";
    }
    else if (zero * 2 < one && one <= 2 * (zero + 1))
    {
        for (int i = 0; i < zero; i++)
            cout << "110";
        for (int i = 0; i < one - 2 * zero; i++)
            cout << "1";
    }
    cout << endl;
    system("pause");
    return 0;
}