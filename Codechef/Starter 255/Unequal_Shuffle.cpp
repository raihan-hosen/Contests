#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int a_a = 0, a_b = 0;
    int b_a = 0, b_b = 0;

    for (char c : a)
    {
        if (c == 'a')
            a_a++;
        else
            a_b++;
    }

    for (char c : b)
    {
        if (c == 'a')
            b_a++;
        else
            b_b++;
    }

    int match_ab = min(a_a, b_b);
    int match_ba = min(a_b, b_a);

    int total_matched = match_ab + match_ba;

    if (total_matched == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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