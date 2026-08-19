#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += max(a[i], a[2 * n + 1 - i]);
    }

    cout << sum << endl;
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