#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> st;
    vector<bool> printed(n + 1, false);

    for (int i = 0; i < n; ++i)
    {
        int doc = i + 1;
        char cmd = s[i];

        if (cmd == '1')
        {
            st.push_back(doc);
        }
        else if (cmd == '2')
        {
            if (!st.empty())
            {
                int printed_doc = st.back();
                st.pop_back();
                printed[printed_doc] = true;
            }
            else
            {
                printed[doc] = true;
            }
        }
        else if (cmd == '3')
        {
            printed[doc] = true;
        }
    }

    vector<int> notPrinted;
    for (int i = 1; i <= n; ++i)
    {
        if (!printed[i])
        {
            notPrinted.push_back(i);
        }
    }

    cout << notPrinted.size() << endl;
    for (int i = 0; i < notPrinted.size(); ++i)
    {
        cout << notPrinted[i] << (i + 1 == notPrinted.size() ? "" : " ");
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}