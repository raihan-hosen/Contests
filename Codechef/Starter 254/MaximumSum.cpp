#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<long long int> a(n);
    vector<long long int> pref(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    
    long long int max_sum = 0;
    int len = n - k;
    
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = i + len;
        long long int current_sum = pref[right] - pref[left];
        max_sum = max(max_sum, current_sum);
    }
    
    cout << max_sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
