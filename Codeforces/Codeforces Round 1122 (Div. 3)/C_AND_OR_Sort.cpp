#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s[0] == '1')
    {
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zeros++;
            }
        }
        cout << zeros << endl;
        return;
    }

    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : 0);
    }

    vector<int> suff(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i + 1] = suff[i + 2] + (s[i] == '0' ? 1 : 0);
    }

    int ans = n;
    for (int k = idx; k <= n; k++)
    {
        int ops = pref[k] + suff[k + 1];
        ans = min(ans, ops);
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