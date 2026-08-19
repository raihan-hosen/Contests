#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll sum = 0, max_num = 0;
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        sum += x;
        max_num = max(max_num, x);

        if (sum - max_num <= k)
        {
            ans = i;
        }
    }

    cout << ans << endl;
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