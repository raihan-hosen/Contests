#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

auto printVector(const vector<ll> &vec, bool &first)
{
    for (ll val : vec)
    {
        if (!first)
        {
            cout << " ";
        }
        cout << val;
        first = false;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<ll> left, mid, right;
    int visCount = 0;

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && v[j] == v[i])
        {
            j++;
        }
        int count = j - i;

        left.push_back(v[i]);
        visCount++;

        if (count >= 2)
        {
            right.push_back(v[i]);
            visCount++;
        }

        for (int c = 2; c < count; c++)
        {
            mid.push_back(v[i]);
        }

        i = j;
    }

    reverse(right.begin(), right.end());

    cout << visCount << endl;
    bool first = true;

    printVector(left, first);
    printVector(mid, first);
    printVector(right, first);
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