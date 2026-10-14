#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a <= b)
    {
        cout << -1 << endl;
    }
    else
    {
        int ans = min(b, a - b);
        cout << ans << endl;
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