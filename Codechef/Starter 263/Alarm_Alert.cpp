#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll xVal, yVal, dVal, minTime = -1;
    cin >> xVal >> yVal >> dVal;

    ll startA = (yVal + xVal - 1) / xVal;
    for (ll i = startA;; i++)
    {
        ll rem = (i * xVal) % yVal;
        if (rem <= dVal)
        {
            minTime = i * xVal;
            break;
        }
    }

    ll startB = (xVal + yVal - 1) / yVal;
    for (ll i = startB;; i++)
    {
        ll rem = (i * yVal) % xVal;
        if (rem <= dVal)
        {
            ll candB = i * yVal;
            if (minTime == -1 || candB < minTime)
            {
                minTime = candB;
            }
            break;
        }
    }

    cout << minTime << endl;
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