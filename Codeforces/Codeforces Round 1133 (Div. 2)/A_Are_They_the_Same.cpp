#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll evenA = 0, oddA = 0;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        if (val % 2 == 0)
        {
            evenA++;
        }
        else
        {
            oddA++;
        }
    }

    ll evenB = 0, oddB = 0;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        if (val % 2 == 0)
        {
            evenB++;
        }
        else
        {
            oddB++;
        }
    }

    if (k % 2 == 0)
    {
        if (evenA <= evenB)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        if (oddA <= oddB)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}