#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
bool is_all_odd(string n)
{
    for (int i = 0; i < n.length(); i++)
        if ((n[i] - '0') % 2 == 0)
            return false;
    return true;
}
int main()
{
    string n;
    cin >> n;
    if (is_all_odd(n))
        cout << "-1" << endl;
    else
    {
        bool flag = false;
        int pos = string::npos;
        int len = n.size();
        int n_l = n[len - 1] - '0';
        for (int i = 0; i < n.length(); i++)
        {
            int t = n[i] - '0';
            if (t % 2 == 0)
            {
                if (n_l > t)
                {
                    char tmp = n[len - 1];
                    n[len - 1] = n[i];
                    n[i] = tmp;
                    flag = true;
                    pos = i;
                    break;
                }
                else
                    pos = i;
            }
        }
        cout << flag << ' ' << pos << endl;
        if (!flag && pos != string::npos)
        {
            char tmp = n[len - 1];
            n[len - 1] = n[pos];
            n[pos] = tmp;
        }
        cout << n << endl;
    }
    system("pause");
    return 0;
}