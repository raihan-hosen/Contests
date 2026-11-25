#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());

    ll ans = sum - a[n - 1];

    for (int i = 0; i < n; i++)
    {
        ll otherMax = (i == n - 1) ? a[n - 2] : a[n - 1];
        ll newMax = max(otherMax, 2 * a[i]);
        ll currentScore = (sum + a[i]) - newMax;
        ans = max(ans, currentScore);
    }

    cout << ans << endl;
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