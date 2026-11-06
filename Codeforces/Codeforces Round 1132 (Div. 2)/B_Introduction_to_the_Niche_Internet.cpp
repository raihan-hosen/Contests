#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll maxVal = a[n - 1];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxVal)
        {
            c++;
        }
    }

    if (k < c)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int r = n - k;
    vector<ll> res;

    for (int i = r; i < n - c; i++)
    {
        res.push_back(a[i]);
    }

    for (int i = n - c; i < n; i++)
    {
        res.push_back(a[i]);
    }

    for (int i = r - 1; i >= 0; i--)
    {
        res.push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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