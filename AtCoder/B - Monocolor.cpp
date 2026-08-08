#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> c(n);
    vector<ll> freq(n + 1, 0);

    ll max_freq = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
        freq[c[i]]++;
        if (freq[c[i]] > max_freq)
        {
            max_freq = freq[c[i]];
        }
    }

    cout << n - max_freq << endl;
}

int main()
{
    solve();

    return 0;
}