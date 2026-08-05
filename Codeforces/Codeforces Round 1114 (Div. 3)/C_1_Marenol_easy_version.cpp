#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    ll count1 = 0, count0 = 0;
    ll even1 = 0, even0 = 0;

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            count1++;
            if (i % 2 == 0)
            {
                even1++;
            }
        }
        if (b[i] == '1')
        {
            count0++;
            if (i % 2 == 0)
            {
                even0++;
            }
        }
    }

    if (count1 == count0 && even1 == even0)
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
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}