#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k = m - 1;
    priority_queue<long long> pq;

    long long sum = 0;
    long long ans = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        if (i >= m - 1)
        {
            long long val = m * a[i] - sum;
            ans = max(ans, val);
        }

        if (k > 0)
        {
            if ((int)pq.size() < k)
            {
                pq.push(a[i]);
                sum += a[i];
            }
            else if (!pq.empty() && a[i] < pq.top())
            {
                sum += a[i] - pq.top();
                pq.pop();
                pq.push(a[i]);
            }
        }
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
