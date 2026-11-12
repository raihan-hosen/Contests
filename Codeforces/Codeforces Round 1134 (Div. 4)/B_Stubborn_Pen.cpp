#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    char curColor = 'R';
    ll manual = 0;

    for (int i = 0; i < n; i++)
    {
        if (curColor != s[i])
        {
            manual++;
            curColor = s[i];
        }
        curColor = (curColor == 'R' ? 'B' : 'R');
    }

    cout << manual << endl;
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