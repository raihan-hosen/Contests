#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<ll> a;
vector<ll> pos_list;
vector<ll> pos_in_vec;

void add_pos(ll x)
{
    if (pos_in_vec[x] == -1)
    {
        pos_in_vec[x] = pos_list.size();
        pos_list.push_back(x);
    }
}

void remove_pos(ll x)
{
    ll p = pos_in_vec[x];
    ll last = pos_list.back();
    pos_list[p] = last;
    pos_in_vec[last] = p;
    pos_list.pop_back();
    pos_in_vec[x] = -1;
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    a.assign(n + 1, 0);
    pos_in_vec.assign(n + 1, -1);
    pos_list.clear();

    ll current_xor = 0;

    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            current_xor ^= a[x];
            a[x]++;
            current_xor ^= a[x];
            add_pos(x);
        }
        else
        {
            vector<ll> active = pos_list;
            for (ll x : active)
            {
                current_xor ^= a[x];
                a[x]--;
                current_xor ^= a[x];
                if (a[x] == 0)
                {
                    remove_pos(x);
                }
            }
        }
        cout << current_xor << endl;
    }
}

int main()
{
    solve();

    return 0;
}