#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    if (n <= 3)
    {
        cout << n * x << endl;
    }
    else
    {
        cout << (3 * x) + ((n - 3) * y) << endl;
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