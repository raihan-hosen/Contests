#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int k = (n + 1) / 2;

    vector<int> mn(k + 1);
    vector<int> mx(k + 1);

    mn[1] = pos[1];
    mx[1] = pos[1];

    for (int i = 2; i <= k; i++)
    {
        mn[i] = min(mn[i - 1], pos[i]);
        mx[i] = max(mx[i - 1], pos[i]);
    }

    vector<int> low(k + 1);
    vector<int> high(k + 1);

    for (int i = 1; i <= k; i++)
    {
        low[i] = max(1, mx[i] - 2 * i + 2);
        high[i] = min(n - 2 * i + 2, mn[i]);
    }

    low[1] = max(low[1], pos[1]);
    high[1] = min(high[1], pos[1]);

    for (int i = k - 1; i >= 1; i--)
    {
        low[i] = max(low[i], low[i + 1]);
        high[i] = min(high[i], high[i + 1] + 2);
    }

    for (int i = 1; i <= k; i++)
    {
        if (low[i] > high[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> ansL(k + 1);
    ansL[1] = pos[1];

    for (int i = 2; i <= k; i++)
    {
        ansL[i] = max(low[i], ansL[i - 1] - 2);
    }

    for (int i = 1; i <= k; i++)
    {
        int l = ansL[i];
        int r = l + 2 * i - 2;
        cout << l << " " << r << endl;
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
