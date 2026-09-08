#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;

    ll n = y - x;
    ll total = 0;

    ll i = 0;
    while (i < k && (x + i) <= n)
    {
        total += (y + i) % (x + i);
        i++;
    }

    if (i < k)
    {
        ll remaining = k - i;
        total += remaining * n;
    }

    cout << total << endl;
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