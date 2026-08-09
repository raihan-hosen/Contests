#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll MOD = 998244353;

ll get_ways(const string &sub)
{
    int m = sub.size();
    bool p0_valid = true;
    bool p1_valid = true;

    for (int i = 0; i < m; i++)
    {
        if (sub[i] != '?')
        {
            int val = sub[i] - '0';
            if (val != (i % 2))
            {
                p0_valid = false;
            }
            if (val != ((i + 1) % 2))
            {
                p1_valid = false;
            }
        }
    }

    ll ways = 0;
    if (p0_valid)
        ways++;
    if (p1_valid)
        ways++;
    return ways;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string even_sub = "";
    string odd_sub = "";

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even_sub += s[i];
        }
        else
        {
            odd_sub += s[i];
        }
    }

    ll even_ways = get_ways(even_sub);
    ll odd_ways = get_ways(odd_sub);

    ll ans = (even_ways * odd_ways) % MOD;
    cout << ans << endl;
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