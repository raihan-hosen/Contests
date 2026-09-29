#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;

    int totalOne = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            totalOne++;
        }
    }

    bool found = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            found = true;

        else if (found && k > 0)
        {
            totalOne++;
            k--;
        }
    }

    cout << totalOne << endl;
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