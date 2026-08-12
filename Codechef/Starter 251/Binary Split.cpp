#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_k = 0;
    int min_m = INT_MAX;

    int i = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            int zero_start = i;
            while (i < n && s[i] == '0')
            {
                i++;
            }
            int k = i - zero_start;

            if (i < n && s[i] == '1')
            {
                int one_start = i;
                while (i < n && s[i] == '1')
                {
                    i++;
                }
                int m = i - one_start;

                if (k > max_k)
                {
                    max_k = k;
                    min_m = m;
                }
                else if (k == max_k)
                {
                    min_m = min(min_m, m);
                }
            }
        }
        else
        {
            i++;
        }
    }

    if (max_k == 0)
    {
        cout << s << endl;
    }
    else
    {
        string ans = string(max_k, '0') + string(min_m, '1');
        cout << ans << endl;
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