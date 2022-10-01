#include <bits/stdc++.h>

#define fore(i,a,b) for(int i = (a), T = (b); i < T; ++i)
#define ENDL '\n'

using namespace std;

typedef long long lli;

int main(){
    lli n,m, res;
    cin>>n>>m;
    if (n <= m) cout << 1 << ENDL;

    else {
        res = n / m;
        if (n % m != 0) cout << res + 1 << ENDL;
        else cout << res << ENDL;
    }

    return 0;
}