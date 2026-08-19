#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> pref0(n + 1, 0);
    vector<int> pref1(n + 1, 0);
    vector<int> pref2(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        pref0[i] = pref0[i - 1];
        pref1[i] = pref1[i - 1];
        pref2[i] = pref2[i - 1];

        if (x == 0)
        {
            pref0[i]++;
        }
        else if (x == 1)
        {
            pref1[i]++;
        }
        else if (x == 2)
        {
            pref2[i]++;
        }
    }

    for (int k = 0; k < q; k++)
    {
        int l, r;
        cin >> l >> r;

        int count0 = pref0[r] - pref0[l - 1];
        int count1 = pref1[r] - pref1[l - 1];
        int count2 = pref2[r] - pref2[l - 1];

        if (count0 == 0)
        {
            cout << 0 << endl;
        }
        else if (count1 == 0)
        {
            cout << 1 << endl;
        }
        else if (count2 == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}