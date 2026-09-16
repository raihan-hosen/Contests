#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k <= n)
    {
        cout << 0 << endl;
    }
    else
    {
        int ans = 2 * (k - n);
        cout << ans << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}