#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    ll minCoins = 0;

    for (ll i = 0; i < n / 2; i++)
    {
        char left = s[i];
        char right = s[n - 1 - i];

        if (left != right)
        {
            if (left == c || right == c)
            {
                minCoins += 1;
            }
            else
            {
                minCoins += 2;
            }
        }
    }

    cout << minCoins << endl;
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