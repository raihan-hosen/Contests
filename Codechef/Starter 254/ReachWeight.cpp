#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int cost = 0;
    if (n % 2 == 0) {
        cost = (n / 2) * 30;
    } else {
        cost = ((n - 1) / 2) * 30 + 20;
    }
    cout << cost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
