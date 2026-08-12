#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    queue<ll> q;
    vector<ll> dist(500, -1);

    q.push(n);
    dist[n] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        if (u % 3 == 0)
        {
            cout << dist[u] << "\n";
            return;
        }

        ll v1 = u + 1;
        if (v1 < 500 && dist[v1] == -1)
        {
            dist[v1] = dist[u] + 1;
            q.push(v1);
        }

        ll v2 = ((u / 5) + 1) * 5;
        if (v2 < 500 && dist[v2] == -1)
        {
            dist[v2] = dist[u] + 1;
            q.push(v2);
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}