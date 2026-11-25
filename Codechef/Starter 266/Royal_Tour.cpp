#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return max(abs(a.first - b.first), abs(a.second - b.second));
}

void solve()
{
    ll n, m, r, c;
    cin >> n >> m >> r >> c;

    pair<ll, ll> start = {r, c};
    vector<pair<ll, ll>> corners = {
        {1, 1},
        {1, m},
        {n, 1},
        {n, m}};

    vector<int> idx = {0, 1, 2, 3};
    ll minMoves = LLONG_MAX;

    do
    {
        ll currentMoves = dist(start, corners[idx[0]]) + dist(corners[idx[0]], corners[idx[1]]) + dist(corners[idx[1]], corners[idx[2]]) + dist(corners[idx[2]], corners[idx[3]]);
        minMoves = min(minMoves, currentMoves);
    } while (next_permutation(idx.begin(), idx.end()));

    cout << minMoves << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}