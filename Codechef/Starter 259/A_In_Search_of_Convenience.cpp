#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll x0, y0, R;
    cin >> x0 >> y0 >> R;

    for (ll x = x0 - R; x <= x0 + R; ++x)
    {
        ll rem = R * R - (x0 - x) * (x0 - x);
        if (rem < 0)
            continue;

        ll dy = round(sqrt(rem));
        if (dy * dy == rem)
        {
            ll y1 = y0 + dy;
            ll y2 = y0 - dy;

            if ((x0 - x) * (x0 - x) + (y0 - y1) * (y0 - y1) == R * R)
            {
                cout << x << " " << y1 << endl;
                return;
            }
            if ((x0 - x) * (x0 - x) + (y0 - y2) * (y0 - y2) == R * R)
            {
                cout << x << " " << y2 << endl;
                return;
            }
        }
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