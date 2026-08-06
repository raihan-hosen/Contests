#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> freq(1005, 0);

    ll total_sum = 0;
    ll max_freq = 0;
    ll max_val = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
        freq[a[i]]++;

        if (freq[a[i]] > max_freq)
        {
            max_freq = freq[a[i]];
            max_val = a[i];
        }
    }

    ll limit = (n + 1) / 2;
    if (max_freq <= limit)
    {
        cout << total_sum << endl;
    }
    else
    {
        ll wasted = 2 * max_freq - n - 2;
        ll ans = total_sum - wasted * max_val;
        cout << ans << endl;
    }
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