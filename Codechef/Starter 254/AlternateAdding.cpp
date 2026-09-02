#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector < long long int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector < long long int > b(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            b[i] = -a[i];
        }
        else {
            b[i] = a[i];
        }
    }

    vector < long long int > diff(n);
    diff[0] = b[0];
    for (int i = 1; i < n; i++) {
        diff[i] = b[i] - b[i - 1];
    }

    long long pos_sum = 0;
    long long neg_sum = 0;

    for (int i = 0; i < n; i++) {
        if (diff[i] > 0) {
            pos_sum += diff[i];
        }
        else {
            neg_sum += (-diff[i]);
        }
    }

    cout << max(pos_sum, neg_sum) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
