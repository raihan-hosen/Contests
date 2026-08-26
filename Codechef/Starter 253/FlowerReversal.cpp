#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll len;
    string str;
    cin >> len >> str;

    ll total_beauty = 0;
    ll count_01 = 0;
    ll count_10 = 0;

    for (ll idx = 0; idx < len - 1; idx++)
    {
        if (str[idx] == str[idx + 1])
        {
            total_beauty++;
        }
        else
        {
            if (str[idx] == '0')
                count_01++;
            else
                count_10++;
        }
    }

    if (count_01 >= 2 || count_10 >= 2)
        total_beauty += 2;
    else if (count_01 >= 1 && count_10 >= 1)
        total_beauty++;

    cout << total_beauty << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}