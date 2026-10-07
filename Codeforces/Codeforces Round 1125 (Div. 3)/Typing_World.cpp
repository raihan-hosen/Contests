#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, l;
    cin >> s >> l;

    vector<bool> isLeft(26, false);
    for (char ch : l)
    {
        isLeft[ch - 'a'] = true;
    }

    int maxConsecutive = 0;
    int currentConsecutive = 0;
    char previous = ' ';

    for (int i = 0; i < n; ++i)
    {
        char current = isLeft[s[i] - 'a'] ? 'L' : 'R';

        if (current == previous)
        {
            currentConsecutive++;
        }
        else
        {
            currentConsecutive = 1;
            previous = current;
        }

        maxConsecutive = max(maxConsecutive, currentConsecutive);
    }

    cout << maxConsecutive << endl;
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