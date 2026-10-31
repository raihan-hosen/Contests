#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll x, y, z, a;
    char c;
    cin >> x >> y >> z;

    a = x + y + z;
    if (y >= z)
    {
        c = 'R';
    }
    else if (z >= x)
    {
        c = 'S';
    }
    else
    {
        c = 'P';
    }

    for (int i = 0; i < a; i++)
    {
        cout << c;
    }

    cout << endl;
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