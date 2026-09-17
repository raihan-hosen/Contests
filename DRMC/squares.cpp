#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total = n * n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = i * n + j + 1;

            int r = i % 4;
            int c = j % 4;

            if (r == c || r + c == 3)
            {
                value = total + 1 - value;
            }

            if (j)
                cout << ' ';
            cout << value;
        }
        cout << '\n';
    }

    return 0;
}