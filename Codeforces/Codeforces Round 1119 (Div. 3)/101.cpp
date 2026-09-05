#include<bits/stdc++.h>
using namespace std;
 
void check(int st, int en, const vector<int>& a, int& mx, int& ansL, int& ansR)
{
    int first = -1;
    int last = -1;
 
    for (int i = st; i <= en; i++)
    {
        if (a[i] != 0)
        {
            if (first == -1) first = i;
            last = i;
        }
    }
 
    if (first != -1)
    {
        int len = last - first + 1;
        if (len > mx)
        {
            mx = len;
            ansL = first;
            ansR = last;
        }
    }
}
 
void solve()
{
    int n;
    cin >> n;
 
    int mx = 0;
    int ansL = -1;
    int ansR = -1;
 
    vector<int> a(n + 1);
    vector<int> one;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            one.push_back(i);
        }
    }
 
    if (one.empty())
    {
        check(1, n, a, mx, ansL, ansR);
    }
    else
    {
        check(1, one[0], a, mx, ansL, ansR);
        for (size_t k = 0; k + 1 < one.size(); k++)
        {
            check(one[k], one[k + 1], a, mx, ansL, ansR);
        }
        check(one.back(), n, a, mx, ansL, ansR);
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            if (i == ansL || i == ansR)
            {
                a[i] = 1;
            }
            else
            {
                a[i] = 0;
            }
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << endl;
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
