#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int l, r;
    cin >> l >> r;

    if (l > 0 || r < 0)
    {
        cout << r - l << endl;
    }
    else
    {
        int ans = max(0, abs(l + r) - 1);
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}