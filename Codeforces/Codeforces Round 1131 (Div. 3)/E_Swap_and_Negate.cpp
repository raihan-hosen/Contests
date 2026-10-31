#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        int idx = i + 1;
        if (idx % 2 != 0)
        {
            b[i] = -val;
        }
        else
        {
            b[i] = val;
        }
    }

    sort(b.begin(), b.end());

    int oddCnt = (n + 1) / 2;
    ll ans = 0;

    for (int i = 0; i < oddCnt; i++)
    {
        ans -= b[i];
    }

    for (int i = oddCnt; i < n; i++)
    {
        ans += b[i];
    }

    cout << ans << endl;
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