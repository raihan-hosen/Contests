#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<ll, ll> sum;

    for (int i = 0; i < n; i++)
    {
        ll g = gcd(a[i], x);
        if (g <= 1)
            continue;

        for (ll d = 1; d * d <= g; d++)
        {
            if (g % d == 0)
            {
                if (d > 1)
                {
                    sum[d] += a[i];
                }
                if (g / d != d && (g / d) > 1)
                {
                    sum[g / d] += a[i];
                }
            }
        }
    }

    ll maxCoins = 0;
    for (auto const &[d, total] : sum)
    {
        maxCoins = max(maxCoins, total);
    }

    cout << maxCoins << endl;
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