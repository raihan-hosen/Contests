#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string min_s = "";

    for (int i = 0; i <= n - k; i++)
    {
        string temp = s;
        sort(temp.begin() + i, temp.begin() + i + k);

        if (min_s == "" || temp < min_s)
        {
            min_s = temp;
        }
    }

    cout << min_s << endl;
}

int main()
{
    solve();

    return 0;
}