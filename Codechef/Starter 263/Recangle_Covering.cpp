#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, m;
    cin >> n >> m;

    int minR = n, maxR = -1;
    int minC = m, maxC = -1;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
            {
                minR = min(minR, i);
                maxR = max(maxR, i);
                minC = min(minC, j);
                maxC = max(maxC, j);
            }
        }
    }

    ll height = maxR - minR + 1;
    ll width = maxC - minC + 1;
    ll ans = height * width;

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