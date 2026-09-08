#include <bits/stdc++.h>
using namespace std;
using ll=long long int;

void solve() {
    long long R, B, G;
    cin >> R >> B >> G;

    ll bundles = min({R, B, G});

    ll rem_R = R - bundles;
    ll rem_B = B - bundles;
    ll rem_G = G - bundles;

    ll total = (bundles * 10) + (rem_R + rem_B + rem_G) * 3;

    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
