#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int x, y, m;
    cin >> x >> y >> m;

    string s;
    cin >> s;

    int maxStates = x + m + 2;
    vector<int> maxY(maxStates, -1);
    maxY[x] = y;

    int ans = x + y;

    for (int i = 0; i < m; i++)
    {
        vector<int> nextY(maxStates, -1);
        for (int curX = 0; curX < maxStates; curX++)
        {
            int curY = maxY[curX];
            if (curY == -1)
                continue;

            if (s[i] == '+')
            {
                if (curY >= 1)
                {
                    nextY[curX] = max(nextY[curX], curY + 1);
                }
                else if (curX >= 1)
                {
                    nextY[curX - 1] = max(nextY[curX - 1], 1);
                }
            }
            else
            {
                if (curY >= 1)
                {
                    nextY[curX + 1] = max(nextY[curX + 1], curY - 1);
                }
                if (curX >= 1)
                {
                    nextY[curX - 1] = max(nextY[curX - 1], curY);
                }
            }
        }

        maxY = nextY;
        for (int curX = 0; curX < maxStates; curX++)
        {
            if (maxY[curX] != -1)
            {
                ans = max(ans, curX + maxY[curX]);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}