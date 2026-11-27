#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, k, p;
    cin >> n >> k >> p;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll total = 0;
    ll i = 0;

    while (i + k <= n)
    {
        ll blockSum = 0;
        for (int j = 0; j < k; j++)
        {
            blockSum += a[i + j];
        }
        total += max(p, blockSum);
        i += k;
    }

    while (i < n)
    {
        total += a[i];
        i++;
    }

    cout << total << endl;
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