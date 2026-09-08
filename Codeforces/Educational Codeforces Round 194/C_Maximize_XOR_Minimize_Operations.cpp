#include <iostream>
using namespace std;
using ll = long long int;

void solve()
{
    ll a, b;
    cin >> a >> b;

    ll total = a + b;
    ll modified_a = a;
    int target_bit = -1;
    for (int i = 60; i >= 0; i--)
    {
        if ((a & (1LL << i)) && !(total & (1LL << i)))
        {
            target_bit = i;
            break;
        }
    }
    if (target_bit != -1)
    {
        ll upper = (a >> (target_bit + 1)) << (target_bit + 1);
        ll lower = total & ((1LL << target_bit) - 1);
        modified_a = upper | lower;
    }

    ll difference = a - modified_a;
    cout << total << " " << difference << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}