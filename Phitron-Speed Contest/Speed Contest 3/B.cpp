#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n % 2 == 0)
    {
        cout << (n / 2) + 1 << endl;
    }
    else
    {
        cout << (n - 1) / 2 << endl;
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