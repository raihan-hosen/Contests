#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(31, 0);
    int max_v = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int msb = 0;
        while (x > 1) {
            x = x / 2;
            msb++;
        }

        v[msb]++;
        max_v = max(max_v, v[msb]);
    }

    cout << max_v << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
