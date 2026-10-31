#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    string p, q;
    cin >> p >> q;

    vector<int> cntP(26, 0);
    vector<int> cntQ(26, 0);

    for (char c : p)
    {
        cntP[c - 'a']++;
    }
    for (char c : q)
    {
        cntQ[c - 'a']++;
    }

    bool isOk = true;

    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        int diff = cntP[i] - cntQ[i];

        if (c == 's' || c == 'i' || c == 'x')
        {
            if (diff != 1)
            {
                isOk = false;
            }
        }
        else
        {
            if (diff != 0)
            {
                isOk = false;
            }
        }
    }

    if (isOk)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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