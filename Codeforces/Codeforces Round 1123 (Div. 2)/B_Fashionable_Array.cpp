#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<ll> ans;
    int k = 1;
    while (true)
    {
        vector<ll> current;
        for (auto p : freq)
        {
            if (p.second >= k)
            {
                current.push_back(p.first);
            }
        }

        if (current.empty())
        {
            break;
        }
        sort(current.rbegin(), current.rend());

        for (int val : current)
        {
            ans.push_back(val);
        }
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
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