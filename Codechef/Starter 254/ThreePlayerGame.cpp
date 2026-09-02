#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        long long int max = n / 2;
        int rem = (3 - (n % 3)) % 3;

        long long int dif = max - ((max - rem) % 3 + 3) % 3;

        if (dif < 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << n + dif + 1 << endl;
        }
    }

    return 0;
}
