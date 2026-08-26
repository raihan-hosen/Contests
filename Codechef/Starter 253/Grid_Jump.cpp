#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long A, B, P, Q, R;
    cin >> A >> B >> P >> Q >> R;

    long long min_cost = -1;

    long long max_diag = min(A, B);
    for (long long d = 0; d <= max_diag; d++)
    {
        long long current_cost = d * R;

        long long rem_A = A - d;
        long long rem_B = B - d;

        current_cost += ((rem_A + 1) / 2) * P;

        current_cost += ((rem_B + 1) / 2) * Q;

        if (min_cost == -1 || current_cost < min_cost)
        {
            min_cost = current_cost;
        }
    }

    cout << min_cost << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}