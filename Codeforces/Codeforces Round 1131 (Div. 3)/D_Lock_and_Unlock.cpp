#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll medianVal = a[n / 2];
    ll minCost = 0;

    for (int i = 0; i < n; i++)
    {
        minCost += abs(a[i] - medianVal);
    }

    ll minOps = a[n - 1] - a[0];

    cout << minCost << " " << minOps << endl;
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