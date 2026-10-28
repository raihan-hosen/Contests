#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    int i = 0;

    while (i < n)
    {
        if (s[i] == '1')
        {
            ans++;
            int p = min(n - 1, i + k);
            i = p + 1;
        }
        else
        {
            i++;
        }
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