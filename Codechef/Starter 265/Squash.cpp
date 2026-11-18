#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int blocks = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            blocks++;
        }
    }

    if (k >= blocks && k <= n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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