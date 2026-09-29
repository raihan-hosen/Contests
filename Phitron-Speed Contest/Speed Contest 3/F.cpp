#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int c1 = 0, c2 = 0, c3 = 0;
    for (char ch : s1)
    {
        if (ch == '1')
        {
            c1++;
        }
    }

    for (char ch : s2)
    {
        if (ch == '1')
        {
            c2++;
        }
    }

    for (char ch : s3)
    {
        if (ch == '1')
        {
            c3++;
        }
    }

    int totalOnes = c1 + c2 + c3;
    int minOps = 1e9;

    int targets[2] = {0, n};

    for (int t1 : targets)
    {
        for (int t2 : targets)
        {
            for (int t3 : targets)
            {
                if (t1 + t2 + t3 == totalOnes)
                {
                    int ops = (abs(c1 - t1) + abs(c2 - t2) + abs(c3 - t3)) / 2;
                    minOps = min(minOps, ops);
                }
            }
        }
    }

    if (minOps == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minOps << endl;
    }
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