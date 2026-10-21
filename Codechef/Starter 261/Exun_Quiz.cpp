#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n, s;
    cin >> n >> s;

    ll attempts = -1;

    for (ll c = 0; c <= n; ++c)
    {
        ll w = 4 * c - s;

        if (w >= 0 && (c + w) <= n)
        {
            ll currentAttempts = c + w;
            if (attempts == -1 || currentAttempts < attempts)
            {
                attempts = currentAttempts;
            }
        }
    }

    cout << attempts << endl;
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