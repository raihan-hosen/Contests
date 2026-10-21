#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool hasDigit(ll n, ll d)
{
    if (n == 0 && d == 0)
    {
        return true;
    }
    while (n > 0)
    {
        if (n % 10 == d)
        {
            return true;
        }
        n /= 10;
    }
    return false;
}

void solve()
{
    ll n, d;
    cin >> n >> d;

    string s = to_string(n);
    char bad = '0' + d;

    int idx = -1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == bad)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << n << endl;
        return;
    }

    string t = s;
    int i = idx;
    while (i >= 0)
    {
        int val = t[i] - '0';
        val++;
        while (val == d && val <= 9)
            val++;

        if (val <= 9)
        {
            t[i] = '0' + val;
            int min_dig = (d == 0) ? 1 : 0;
            for (int j = i + 1; j < t.length(); ++j)
            {
                if (min_dig == d)
                    min_dig++;
                t[j] = '0' + min_dig;
            }
            cout << stoll(t) << endl;
            return;
        }
        else
        {
            i--;
        }
    }

    int minDig = (d == 0) ? 1 : 0;
    string res = "";
    res += ('0' + minDig);

    int nextDig = 0;
    if (nextDig == d)
    {
        nextDig++;
    }
    for (int j = 0; j < s.length(); ++j)
    {
        res += ('0' + nextDig);
    }
    cout << stoll(res) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}