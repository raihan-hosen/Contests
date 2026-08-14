#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll min_val;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            min_val = a[i];
        }
        else
        {
            min_val = min(min_val, a[i]);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == min_val)
        {
            count++;
        }
    }

    if (count >= 2)
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}