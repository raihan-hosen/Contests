#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int p_valid = n;
    int p = 0;
    for (ll i = 1; i <= n; i++)
    {
        p = a[i] - p;
        if (p < 0)
        {
            p_valid = i - 1;
            break;
        }
    }

    int s_valid = 1;
    int s = 0;
    for (ll i = n; i >= 1; i--)
    {
        s = a[i] - s;
        if (s < 0)
        {
            s_valid = i + 1;
            break;
        }
    }

    int left = max(1, s_valid - 1);
    int right = min(n, p_valid + 1);

    int ans = max(0, right - left + 1);
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