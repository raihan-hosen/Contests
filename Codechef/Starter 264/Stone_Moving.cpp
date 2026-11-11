#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> diff(n + 2, 0);
    ll total = 0;
    ll curAdd = 0;

    for (int i = 1; i <= n; i++)
    {
        curAdd += diff[i];
        ll actualA = a[i] + curAdd;
        ll xVal = min(actualA, (ll)(n - i));

        total += xVal;

        if (xVal > 0)
        {
            diff[i + 1] += 1;
            if (i + xVal + 1 <= n + 1)
            {
                diff[i + xVal + 1] -= 1;
            }
        }
    }

    cout << total << endl;
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