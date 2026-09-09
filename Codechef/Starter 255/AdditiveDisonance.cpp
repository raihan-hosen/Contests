#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int maxB = 0;
    int current = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            current++;
        }
        else
        {
            int half = (current + 1) / 2;
            maxB = max(maxB, half);
            current = 1;
        }
    }

    int half = (current + 1) / 2;
    maxB = max(maxB, half);

    cout << maxB << endl;
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
