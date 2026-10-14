#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    bool plusTwo = false;
    bool minusTwo = false;

    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == s[i] && s[i] == s[i + 1])
        {
            plusTwo = true;
        }
        if (s[i - 1] != s[i] && s[i] != s[i + 1])
        {
            minusTwo = true;
        }
    }

    int ans = 1;
    if (plusTwo)
        ans++;
    if (minusTwo)
        ans++;

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