#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    set<ll> paths;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        paths.insert(x - (i + 1));
    }

    int maxLen = 0;
    int currLen = 0;
    ll prevVal = -2e18;

    for (ll val : paths)
    {
        if (val == prevVal + 1)
        {
            currLen++;
        }
        else
        {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
        prevVal = val;
    }

    cout << maxLen << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}