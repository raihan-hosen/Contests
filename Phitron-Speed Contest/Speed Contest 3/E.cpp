#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    ll maxVal = -2e18;
    ll minVal = 2e18;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }

    if (maxVal > 0)
    {
        cout << maxVal << " " << maxVal << endl;
    }
    else if (minVal < 0)
    {
        cout << minVal << " " << minVal << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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