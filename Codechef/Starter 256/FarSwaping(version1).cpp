#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i + 1] && (a[i] - a[i + 1]) > 1)
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << endl;
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
