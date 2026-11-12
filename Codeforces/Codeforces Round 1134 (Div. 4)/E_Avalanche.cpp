#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    ll s = k + 1, ans = 0;

    for (ll i = 1; i <= n; i += s)
    {
        if (v[i] % 2 == 1)
        {
            ans = 1 - ans;
        }
    }

    if (ans == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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