#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int zero_count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            zero_count++;
        }
    }

    if (zero_count == 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    string s(n, 'A');

    if (zero_count == 0)
    {
        cout << s << endl;
        return;
    }

    int zero_seen = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero_seen++;
            if (zero_seen == 1)
            {
                s[i] = 'A';
            }
            else if (zero_seen == 2)
            {
                s[i] = 'B';
            }
            else
            {
                s[i] = 'A';
            }
        }
        else
        {
            s[i] = 'C';
        }
    }

    cout << s << endl;
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
