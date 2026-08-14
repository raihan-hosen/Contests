#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;

    ll odd = 0;
    ll even = 0;

    for (int i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        if (i % 2 != 0)
        {
            odd = max(odd, val);
        }
        else
        {
            even = max(even, val);
        }
    }

    cout << odd + even << endl;
}

int main()
{
    solve();

    return 0;
}