#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(v.begin(), v.end());

    ll initial = v[2] - v[0];
    ll notun = v[1];

    cout << min(initial, notun) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}