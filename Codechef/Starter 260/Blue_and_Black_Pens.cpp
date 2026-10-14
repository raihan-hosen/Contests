#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int a, b;
    cin >> a >> b;

    int ans = min(3 * a, a + b);

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}