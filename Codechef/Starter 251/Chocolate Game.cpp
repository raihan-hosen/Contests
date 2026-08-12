#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll total_sum = 0;
    ll even_sum = 0;
    ll odd_count = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
        even_sum += (a[i] / 2) * 2;
        if (a[i] % 2 != 0)
        {
            odd_count++;
        }
    }

    if (total_sum % 2 == 0)
    {
        ll alice_chocolates = even_sum + (odd_count / 2);
        cout << alice_chocolates << endl;
    }
    else
    {
        ll alice_chocolates = (odd_count - 1) / 2;
        cout << alice_chocolates << endl;
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