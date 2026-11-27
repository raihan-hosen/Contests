#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll l, a, b;
    cin >> l >> a >> b;

    ll g1 = gcd(l, a);
    ll g2 = gcd(l, b);
    ll commonStep = lcm(g1, g2);

    cout << l / commonStep << endl;
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