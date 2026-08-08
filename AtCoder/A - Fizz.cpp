#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}

int main()
{
    solve();

    return 0;
}