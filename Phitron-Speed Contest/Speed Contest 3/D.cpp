#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int zeros = 0, ones = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zeros++;
        }
        else
        {
            ones++;
        }

        if (zeros == ones)
        {
            k++;
        }
    }

    ll reachable = pow(2, k);

    cout << reachable << endl;
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