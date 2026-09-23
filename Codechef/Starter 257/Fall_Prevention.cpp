#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> p(n + 1, 0);
    int firstNeg = -1;

    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
        if (p[i] < 0 && firstNeg == -1)
        {
            firstNeg = i;
        }
    }

    if (firstNeg == -1)
    {
        cout << "YES" << endl;
        return;
    }

    vector<ll> suff(n + 1);
    suff[n] = p[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suff[i] = min(p[i], suff[i + 1]);
    }

    bool possible = false;
    for (int x = 1; x <= firstNeg; x++)
    {
        if (a[x] <= suff[x])
        {
            possible = true;
            break;
        }
    }

    if (possible)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}