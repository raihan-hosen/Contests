#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll ans = n + (n - 1) / (k - 1);

    cout << ans << endl;
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