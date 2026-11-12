#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (b - a == 1 && c - b == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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