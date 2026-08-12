#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, m, x;
    cin >> n >> m >> x;

    ll r = (x + m - 1) / m;
    ll front_dist = r;
    ll back_dist = n - r + 1;

    cout << min(front_dist, back_dist) << endl;
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