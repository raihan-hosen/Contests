#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

void solve()
{
    int n;
    cin >> n;

    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector < int > pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]] = i;
    }
    
    vector < long long > count_ways(n + 1, 0);
    count_ways[1] = 1;

    for (int i = 1; i < n; i++)
    {
        vector < long long > next_count(i + 2, 0);

        if (pos[i] < pos[i + 1])
        {
            long long running_sum = 0;
            for (int k = 2; k <= i + 1; k++)
            {
                running_sum = (running_sum + count_ways[k - 1]) % MOD;
                next_count[k] = running_sum;
            }
        }
        else
        {
            long long running_sum = 0;
            for (int k = i; k >= 1; k--)
            {
                running_sum = (running_sum + count_ways[k]) % MOD;
                next_count[k] = running_sum;
            }
        }

        count_ways = next_count;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + count_ways[i]) % MOD;
    }

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
