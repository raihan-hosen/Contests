#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int base = 0;
    vector<ll> b(n);
    vector<int> left(n, 0);
    vector<int> right(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        b[i] = a[i - 1] - a[i];
        if (b[i] == 0)
        {
            base++;
            left[i] = -1;
            right[i] = -1;
        }
        else if (b[i] == 1)
        {
            left[i] = 1;
        }
        else if (b[i] == -1)
        {
            right[i] = 1;
        }
    }

    int maxLeft = left[0];
    int maxGain = -1e9;

    for (int q = 1; q <= n; q++)
    {
        maxGain = max(maxGain, maxLeft + right[q]);
        if (q < n)
        {
            maxLeft = max(maxLeft, left[q]);
        }
    }

    cout << base + maxGain << endl;
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