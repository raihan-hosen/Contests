#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> merged(25, false);

    for (int i = 0; i < n / 2; i++)
    {
        int u = s[i] - 'a';
        int v = s[n - 1 - i] - 'a';
        if (u > v)
        {
            swap(u, v);
        }
        for (int k = u; k < v; k++)
        {
            merged[k] = true;
        }
    }

    int minOps = 0;
    for (int k = 0; k < 25; k++)
    {
        if (merged[k])
        {
            minOps++;
        }
    }

    cout << minOps << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}