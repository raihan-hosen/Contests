#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;

    queue<int> pending;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            pending.push(x);
        }
        else if (type == 2)
        {
            if (pending.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << pending.front() << endl;
                pending.pop();
            }
        }
    }
}

int main()
{
    solve();

    return 0;
}