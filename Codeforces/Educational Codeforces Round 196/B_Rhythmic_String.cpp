#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxKeep = 0;

    for (int i = 0; i < n; i++)
    {
        int curKeep = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % a[i] == 0)
            {
                curKeep++;
            }
        }
        maxKeep = max(maxKeep, curKeep);
    }

    int ans = n - maxKeep;
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