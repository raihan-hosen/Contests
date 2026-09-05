#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;

    int count_odd = 0;
    int count_e0 = 0;
    int count_e1 = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 != 0)
        {
            count_odd++;
        }
        else
        {
            if ((x / 2) % 2 == 0)
            {
                count_e0++;
            }
            else
            {
                count_e1++;
            }
        }
    }

    int ans = max({count_odd, count_e0, count_e1});
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
