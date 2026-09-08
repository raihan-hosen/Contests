#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 8000 << endl;
    }
    else if (n == 2)
    {
        cout << 4000 << endl;
    }
    else if (n == 3)
    {
        cout << 2000 << endl;
    }
    else if (n == 4)
    {
        cout << 1000 << endl;
    }
}

int main()
{
    solve();
    return 0;
}