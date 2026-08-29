#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(ll n)
{
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    ll i = n / 2;
    while (i < n)
    {
        sum += a[i];
        i++;
    }
    cout << sum << endl;
}

int main()
{
    ll n;
    cin >> n;
    solve(n);
    return 0;
}