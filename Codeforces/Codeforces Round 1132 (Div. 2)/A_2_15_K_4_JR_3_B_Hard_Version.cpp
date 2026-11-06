#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    ll x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        ll curVal = (1LL << v[i]);
        if (x <= y)
        {
            x += curVal;
        }
        else
        {
            y += curVal;
        }
    }

    ll ans = x * y;
    cout << ans << endl;
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