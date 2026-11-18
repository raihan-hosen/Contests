#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    ll maxEarn = 0;

    for (int i = 0; i < n - 1; i++)
    {
        ll currentReduction = (a[i] / 2) + (a[i + 1] / 2);
        ll currentEarnings = total - currentReduction;
        maxEarn = max(maxEarn, currentEarnings);
    }

    cout << maxEarn << endl;
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