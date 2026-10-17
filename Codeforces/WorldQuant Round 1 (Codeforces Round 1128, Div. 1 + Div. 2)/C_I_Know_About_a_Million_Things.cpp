#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int oddCount = 0;
    int evenCount = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 != 0)
        {
            oddCount++;
        }
        else
        {
            evenCount++;
        }
    }

    if (oddCount % 2 != 0 && ((oddCount == 1 && evenCount == 1) || (oddCount == 3 && evenCount == 0)))
    {
        cout << "Larpity" << endl;
    }
    else
    {
        cout << "Moggity" << endl;
    }
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