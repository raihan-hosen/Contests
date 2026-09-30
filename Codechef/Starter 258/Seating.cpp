#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> occupied(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int seat;
        cin >> seat;
        occupied[seat] = true;
    }

    vector<int> result;
    int currentSeat = 1;

    for (int p = 0; p < k; p++)
    {
        while (currentSeat <= n && occupied[currentSeat])
        {
            currentSeat++;
        }

        occupied[currentSeat] = true;
        result.push_back(currentSeat);
    }

    for (int i = 0; i < k; i++)
    {
        cout << result[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;
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