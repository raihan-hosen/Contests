#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(ll n)
{
    vector<ll> frequency(101, 0);

    for (ll i = 0; i < n; i++)
    {
        ll card_value;
        cin >> card_value;

        frequency[card_value]++;
    }

    ll sum = 0;

    for (ll i = 1; i <= 100; i++)
    {
        if (frequency[i] % 2 != 0)
        {
            sum += i;
        }
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
