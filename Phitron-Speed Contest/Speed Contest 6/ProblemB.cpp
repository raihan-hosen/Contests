#include <bits/stdc++.h>
using namespace std;

int main() {
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , x ; cin >> n >> x ;
        if(n<=x) cout << 0 << endl ;
        else {
            int k = n-x ;
            cout << (k*(k+1))/2 << endl ;
        }  

    }
    return 0;
  
}
