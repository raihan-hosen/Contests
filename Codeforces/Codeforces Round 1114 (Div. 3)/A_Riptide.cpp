#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];

    ll rounds = 0;
    while (true)
    {
        sort(v.begin(), v.end());
        if (v[0] == v[1] || v[1] == v[2])
        {
            break;
        }
        v[0]++;
        v[2]--;
        rounds++;
    }

    cout << rounds << endl;
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