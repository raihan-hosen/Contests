#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sumVal = 0;
    ll maxVal = 0;
    bool hasInternal = false;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sumVal += a[i];
        maxVal = max(maxVal, a[i]);
        if (i > 0 && i < n - 1 && a[i] >= 2)
        {
            hasInternal = true;
        }
    }

    if (maxVal < 2)
    {
        cout << -1 << endl;
        return;
    }

    if (hasInternal)
    {
        cout << sumVal - 1 << endl;
    }
    else
    {
        cout << sumVal - (n - 1) << endl;
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