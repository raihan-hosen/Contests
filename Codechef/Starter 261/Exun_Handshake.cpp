#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    ll m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll total = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        ll next = total + a[i];
        ll handshakes = next * (next - 1) / 2;

        if (handshakes <= m)
        {
            total = next;
            count++;
        }
        else
        {
            break;
        }
    }

    cout << count << endl;
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