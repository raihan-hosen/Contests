#include <iostream>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;

    ll half = n / 2;
    ll ans = half * (n - half);

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solve();
    }

    return 0;
}