#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll balance = 0;
    ll pos = 0;

    for (ll j = 2; j <= n; j++)
    {
        ll current = a[j] - j + 1 + pos;
        balance = max(balance, current);

        if (a[j] > 0)
        {
            pos += a[j];
        }
    }

    cout << balance << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}