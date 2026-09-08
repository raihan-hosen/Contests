#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int happy = min(N, M - N);

    cout << happy << endl;

    return 0;
}
