#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int k = 0;
    int firstOne = -1;
    int lastOne = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            k++;
            if (firstOne == -1)
            {
                firstOne = i;
            }
            lastOne = i;
        }
    }

    if (k == 1)
    {
        cout << 0 << endl;
    }
    else if (k == 2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << lastOne - firstOne << endl;
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