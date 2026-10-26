#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll getKth(vector<ll> &a, ll n, ll k)
{
    vector<ll> f(n);
    vector<bool> vis(n + 1, false);
    ll mex = 0;

    for (ll i = 0; i < n; i++)
    {
        vis[a[i]] = true;
        while (vis[mex])
        {
            mex++;
        }
        f[i] = mex;
    }

    sort(f.rbegin(), f.rend());
    return f[k - 1];
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll initKth = getKth(a, n, k);
    ll maxKth = initKth;
    ll ansI = -1, ansJ = -1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            swap(a[i], a[j]);
            ll curKth = getKth(a, n, k);
            if (curKth > maxKth)
            {
                maxKth = curKth;
                ansI = i + 1;
                ansJ = j + 1;
            }
            swap(a[i], a[j]);
        }
    }

    if (maxKth > initKth)
    {
        cout << ansI << " " << ansJ << endl;
    }
    else
    {
        cout << -1 << endl;
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