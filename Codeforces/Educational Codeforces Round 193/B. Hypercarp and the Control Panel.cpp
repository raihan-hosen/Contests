#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> c;
    vector<ll> cnt;

    for (ll i = 0; i < n; i++)
    {
        if (c.empty() || a[i] != c.back())
        {
            c.push_back(a[i]);
            cnt.push_back(1);
        }
        else
        {
            cnt.back()++;
        }
    }

    ll m = c.size();
    ll L0 = m;

    bool can_plus_2 = false;
    for (ll k = 0; k < m - 1; k++)
    {
        if (cnt[k] >= 2 && cnt[k + 1] >= 2)
        {
            can_plus_2 = true;
            break;
        }
    }

    if (can_plus_2)
    {
        cout << L0 + 2 << "\n";
        return;
    }

    bool can_plus_1 = false;
    for (ll k = 0; k < m - 1; k++)
    {
        if (cnt[k] >= 2)
        {
            if (k + 2 >= m || c[k] != c[k + 2])
            {
                can_plus_1 = true;
                break;
            }
        }
        if (cnt[k + 1] >= 2)
        {
            if (k - 1 < 0 || c[k - 1] != c[k + 1])
            {
                can_plus_1 = true;
                break;
            }
        }
    }

    if (can_plus_1)
    {
        cout << L0 + 1 << endl;
    }
    else
    {
        cout << L0 << endl;
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