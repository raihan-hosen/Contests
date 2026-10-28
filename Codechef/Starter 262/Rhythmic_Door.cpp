#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    int curLen = 0;
    char curChar = ' ';

    for (int i = 0; i < n; i++)
    {
        if (s[i] == curChar)
        {
            curLen++;
        }
        else
        {
            curChar = s[i];
            curLen = 1;
        }

        if (curLen == 3)
        {
            count++;
            curLen = 0;
        }
    }

    cout << count << endl;
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