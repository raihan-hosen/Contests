#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int x = n - k;

    if (x == 1)
    {
        cout << "No"<<endl;
    }
    else
    {
        cout << "Yes"<<endl;
    }
}

int main()
{
   int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
