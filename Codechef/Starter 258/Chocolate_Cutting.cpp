#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n, m;
    cin >> n >> m;

    if (n % 2 == 0 || m % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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