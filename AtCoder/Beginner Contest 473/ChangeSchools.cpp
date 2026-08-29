#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(ll n, ll k)
{
    vector<ll> size(k + 1, 0);

    for (ll i = 0; i < n; i++)
    {
        ll class_id;
        cin >> class_id;
        size[class_id]++;
    }

    ll max = 0;
    for (ll i = 1; i <= k; i++)
    {
        if (size[i] > max)
        {
            max = size[i];
        }
    }

    ll count = 0;

    for (ll i = 1; i <= k; i++)
    {
        if (size[i] + 1 >= max)
        {
            count++;
        }
    }

    cout << count << endl;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}
