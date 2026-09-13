#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[p[i]] != i)
        {
            cout << "NO" << endl;
            return;
        }
    }

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (i < p[i])
        {
            v.push_back(p[i]);
        }
    }

    if (v.empty())
    {
        cout << "YES" << endl;
        return;
    }

    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] >= v[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}