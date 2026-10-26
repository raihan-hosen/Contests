#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool checkPossible(ll kVal, ll nVal, ll maxExtra, const vector<ll> &arr)
{
    vector<ll> isoIdx;
    for (ll i = 0; i < nVal; i++)
    {
        bool leftOk = (i > 0 && arr[i] - arr[i - 1] <= kVal);
        bool rightOk = (i < nVal - 1 && arr[i + 1] - arr[i] <= kVal);
        if (!leftOk && !rightOk)
        {
            isoIdx.push_back(i);
        }
    }

    ll totalIso = isoIdx.size();
    ll pairCnt = 0;
    ll curIdx = 0;
    while (curIdx < totalIso - 1)
    {
        if (isoIdx[curIdx + 1] == isoIdx[curIdx] + 1 && arr[isoIdx[curIdx + 1]] - arr[isoIdx[curIdx]] <= 2 * kVal)
        {
            pairCnt++;
            curIdx += 2;
        }
        else
        {
            curIdx += 1;
        }
    }

    return (totalIso - pairCnt) <= maxExtra;
}

void solve()
{
    ll nVal;
    ll maxExtra;
    cin >> nVal >> maxExtra;

    vector<ll> arr(nVal);
    for (ll i = 0; i < nVal; i++)
    {
        cin >> arr[i];
    }

    ll lowVal = 1, highVal = 2e9;
    ll ansVal = highVal;

    while (lowVal <= highVal)
    {
        ll midVal = lowVal + (highVal - lowVal) / 2;
        if (checkPossible(midVal, nVal, maxExtra, arr))
        {
            ansVal = midVal;
            highVal = midVal - 1;
        }
        else
        {
            lowVal = midVal + 1;
        }
    }

    cout << ansVal << endl;
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