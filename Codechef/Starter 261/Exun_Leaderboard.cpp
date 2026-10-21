#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
    {
        cout << x - y - 1 << endl;
    }
    else if (y > x)
    {
        cout << y - x - 1 << endl;
    }
    else
        cout << "0" << endl;
    return 0;
}