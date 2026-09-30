#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    map<ll, ll> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    ll mex = 0;
    while (freq[mex] > 0)
    {
        mex++;
    }

    ll total = 0;
    for (ll v = 0; v < mex; v++)
    {
        if (freq[v] > 1)
        {
            total += (freq[v] - 1) * v;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mex + 1)
        {
            total += (a[i] - (mex + 1));
        }
    }

    if (total % 2 != 0)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
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