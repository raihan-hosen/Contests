#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a > 1)
        {
            total += (a - 1);
        }
    }
    cout << total << endl;
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