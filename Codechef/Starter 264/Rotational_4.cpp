#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int firstDigit = s[i] - '0';
        int secondDigit = s[(i + 1) % n] - '0';
        int val = firstDigit * 10 + secondDigit;

        if (val % 4 == 0)
        {
            count++;
        }
    }

    cout << count << endl;
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