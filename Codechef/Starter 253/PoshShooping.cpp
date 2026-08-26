#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    int max_single = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        max_single = max(max_single, c[i]);
    }

    int max_spent = max_single;

    // Check all pairs (i, j) with i < j such that c[i] <= c[j]
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (c[i] <= c[j])
            {
                max_spent = max(max_spent, c[i] + c[j]);
            }
        }
    }

    cout << max_spent << "\n";
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