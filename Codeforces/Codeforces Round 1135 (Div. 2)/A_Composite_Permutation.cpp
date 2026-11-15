#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;

    if (n <= 3)
    {
        cout << -1 << endl;
        return;
    }

    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    swap(p[1], p[4]);

    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << (i == n ? "" : " ");
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