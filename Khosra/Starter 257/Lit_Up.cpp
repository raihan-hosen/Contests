#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> c(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    ll minCost = 1e9;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            if (i <= 1 + k && j >= n - k && (j - i) <= 2 * k + 1)
            {
                minCost = min(minCost, c[i] + c[j]);
            }
        }
    }

    if (minCost == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minCost << endl;
    }
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