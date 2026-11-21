#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll x;
    cin >> x;

    ll m = 1;
    while (true)
    {
        ll a = (m + 2) / 3;
        ll c = m - a;
        ll maxDmg = a * (2 * c + 3 - a) / 2;

        if (maxDmg >= x)
        {
            cout << m << endl;
            return;
        }
        m++;
    }
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