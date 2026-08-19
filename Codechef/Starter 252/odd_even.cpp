#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    ll odd = 0;
    ll even = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 != 0)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }

    if (odd == even)
    {
        cout << odd + even << endl;
    }
    else
    {
        int min_count = min(odd, even);
        cout << 2 * min_count + 1 << endl;
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