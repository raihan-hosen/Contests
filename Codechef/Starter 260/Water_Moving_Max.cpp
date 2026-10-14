#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int count = min(n, k + 1);
    ll maxWater = 0;

    for (int i = 0; i < count; i++)
    {
        maxWater += a[i];
    }

    cout << maxWater << endl;
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