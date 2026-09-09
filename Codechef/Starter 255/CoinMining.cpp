#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll min_days = 1e18;

    for (int k = 1; k <= 200; k++)
    {
        ll current_profit = 0;
        bool positive = false;
        ll days_needed = 0;

        for (int i = 1; i <= k; i++)
        {
            current_profit += (y * i * i - x);
            if (current_profit > 0)
            {
                days_needed = i;
                positive = true;
                break;
            }
        }

        if (positive)
        {
            min_days = min(min_days, days_needed);
        }
        else
        {
            ll deficit = -current_profit;
            ll daily_income = y * k * k;

            ll extra_days = (deficit / daily_income) + 1;
            days_needed = k + extra_days;

            min_days = min(min_days, days_needed);
        }
    }

    cout << min_days << endl;
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
