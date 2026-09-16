#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector < ll > a(n + 1);
    ll total_sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
    }

    sort(a.begin() + 1, a.end());

    vector < ll > pref(n + 2, 0);
    vector < ll > suff(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        suff[i] = suff[i + 1] + a[i];
    }

    ll max_ans = 0;

    for (int k = 1; k < n; k++)
    {
        ll cr = k;
        ll cb = n - k;
        ll sr = 0;

        if (n - 2 * k >= 0)
        {
            sr = suff[n - k + 1];
        }
        else
        {
            sr = pref[k];
        }

        ll sb = total_sum - sr;
        ll current_ans = sr * cb + sb * cr;

        if (current_ans > max_ans)
        {
            max_ans = current_ans;
        }
    }

    cout << max_ans << endl;
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
