#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    cout << "? 1 " << n << endl;
    int k;
    cin >> k;

    if (k == -1)
        exit(0);

    if (k == 0 || k == n)
    {
        cout << "! NO" << endl;
        return;
    }

    cout << "? 1 " << k << endl;
    int c;
    cin >> c;

    if (c == -1)
    {
        exit(0);
    }

    if (c == k)
    {
        cout << "! NO" << endl;
    }
    else
    {
        cout << "! YES" << endl;
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