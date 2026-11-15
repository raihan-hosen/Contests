#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll cnt1 = 0;
    for (char ch : s)
    {
        if (ch == '1')
        {
            cnt1++;
        }
    }
    ll cnt0 = n - cnt1;

    ll maxChar = min(n, max(cnt1, cnt0) + k);
    ll minChar = n - maxChar;

    ll maxDiversity = 1 + (maxChar * (maxChar + 1)) / 2 + (minChar * (minChar + 1)) / 2;
    cout << maxDiversity << endl;
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