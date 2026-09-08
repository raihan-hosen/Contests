#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int easy = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            easy++;
        }
    }

    if (easy < 2)
    {
        cout << -1 << endl;
        return;
    }

    int count = 0;
    if (a[0] == 1)
        count++;
    if (a[n - 1] == 1)
        count++;

    cout << count << endl;
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