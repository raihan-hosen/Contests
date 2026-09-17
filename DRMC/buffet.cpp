#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Dish
{
    ll sat;
    ll cost;
    ll b;
    ll j;

    bool operator<(const Dish &other) const
    {
        if (sat * other.cost != other.sat * cost)
        {
            return sat * other.cost < other.sat * cost;
        }
        return sat < other.sat;
    }
};

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n + 1);
    vector<ll> b(n + 1);

    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++)
    {
        cin >> b[i];
    }

    priority_queue<Dish> pq;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k && b[i] > 0)
        {
            pq.push({b[i], a[i], b[i], 1});
        }
    }

    ll total_satisfaction = 0;
    ll current_budget = k;

    while (!pq.empty() && current_budget > 0)
    {
        Dish cur = pq.top();
        pq.pop();

        if (cur.cost <= current_budget)
        {
            current_budget -= cur.cost;
            total_satisfaction += cur.sat;

            ll next_j = cur.j + 1;
            ll next_sat = cur.b / next_j;

            if (next_sat > 0)
            {
                pq.push({next_sat, cur.cost, cur.b, next_j});
            }
        }
    }
    cout << total_satisfaction << endl;
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