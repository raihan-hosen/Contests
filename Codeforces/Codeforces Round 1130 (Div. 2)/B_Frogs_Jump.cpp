#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;

    string rowOne, rowTwo;
    cin >> rowOne >> rowTwo;

    int frogs = 0;
    for (int i = 0; i < n; i++)
    {
        int count = (rowOne[i] == 'f') + (rowTwo[i] == 'f');
        if (count == 1)
        {
            frogs++;
        }
    }

    int ans = frogs % 2;
    cout << ans << endl;
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