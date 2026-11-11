#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    ll d;
    cin >> n >> d;

    vector<ll> a(n), b(n);
    ll sumA = 0, sumB = 0, sumMin = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sumA += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sumB += b[i];
        sumMin += min(a[i], b[i]);
    }

    ll costOnly1 = d + sumA;
    ll costOnly2 = d + sumB;
    ll costBoth = 2 * d + sumMin;

    ll ans = min({costOnly1, costOnly2, costBoth});
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