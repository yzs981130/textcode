#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int w[502], b[1002];
bool vis[502];
int main()
{
    int n, m, ans = 0;
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        if (!vis[b[i]])
        {
            v.push_back(b[i]);
            vis[b[i]] = true;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        int j = 0;
        while (v[j] != b[i])
        {
            ans += w[v[j]];
            j++;
        }
        v.erase(v.begin() + j);
        v.insert(v.begin(), b[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}