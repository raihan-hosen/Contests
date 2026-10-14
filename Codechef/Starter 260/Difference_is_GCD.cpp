#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    ll totalPairs = 0;
    ll max = n / 2;

    for (ll l = 1, r; l <= max; l = r + 1)
    {
        ll v = n / l;
        r = min(n / v, max);

        ll count = r - l + 1;
        totalPairs += count * (v - 1);
    }

    cout << totalPairs << endl;
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