#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;

    map<ll, ll> freq;
    ll maxFreq = 0;

    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;

        ll val = a - i;
        freq[val]++;

        maxFreq = max(maxFreq, freq[val]);
    }

    int edits = n - maxFreq;
    cout << edits << endl;
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