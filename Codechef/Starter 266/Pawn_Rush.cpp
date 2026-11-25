#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int r;
    cin >> r;

    if (r == 2)
    {
        cout << 5 << endl;
    }
    else
    {
        cout << 8 - r << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}