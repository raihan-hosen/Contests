#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll T0 = 0, T1 = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            T0++;
        }
        else
        {
            T1++;
        }
    }

    ll k = 1;
    char char1 = s[0];
    char char2 = ' ';

    for (ll i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            k++;
            if (k == 2)
            {
                char2 = s[i];
            }
        }
    }

    ll max_m = -1;

    for (ll m = k; m >= 1; m--)
    {
        ll rem0, rem1;
        if (char1 == '0')
        {
            rem0 = (m + 1) / 2;
            rem1 = m / 2;
        }
        else
        {
            rem1 = (m + 1) / 2;
            rem0 = m / 2;
        }

        ll c0 = T0 - rem0;
        ll c1 = T1 - rem1;

        if (abs(c0 - c1) <= 1)
        {
            max_m = max(max_m, m);
            break;
        }
    }

    if (k >= 2)
    {
        for (ll m = k - 1; m >= 1; m--)
        {
            ll rem0, rem1;
            if (char2 == '0')
            {
                rem0 = (m + 1) / 2;
                rem1 = m / 2;
            }
            else
            {
                rem1 = (m + 1) / 2;
                rem0 = m / 2;
            }

            ll c0 = T0 - rem0;
            ll c1 = T1 - rem1;

            if (abs(c0 - c1) <= 1)
            {
                max_m = max(max_m, m);
                break;
            }
        }
    }

    if (abs(T0 - T1) <= 1)
    {
        max_m = max(max_m, 0LL);
    }

    if (max_m == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << n - max_m << "\n";
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}