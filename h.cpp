/*
Case 1:
3
  1  1    DISTANCIA
1  10  1  T. ESPERA

1: 1 12 14
2: 14  12    1


Case 2:
3
1 5
1 10 1

1: 1  12  18
2: 18 16   1

*/

#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i = a, T = b; i < T; ++i)
#define pb push_back
#define sz(s) int(s.size())
#define ENDL '\n'

using namespace std;

typedef long long lli;
typedef vector<lli> vi;


int main(){ IO;
    lli s; cin >> s;
    lli distances[s-1];
    lli wait_time[s];
    lli stations_ida[s], stations_reg[s];

    fore(i,0,s-1) cin>>distances[i];

    fore(i,0,s) cin>>wait_time[i];

    lli ans = 0;

    fore(j,0,s){
        if (j == 0) stations_ida[j] = wait_time[j];
        else stations_ida[j] = stations_ida[j-1] + distances[j - 1] + wait_time[j];

        if (s - j == s) stations_reg[s - j - 1] = wait_time[s - j - 1];
        else stations_reg[s - j - 1] = stations_reg[s - j ] + distances[s - j - 1] + wait_time[s - j - 1];

    }

    fore(i,0,s){
        lli res = wait_time[i] - abs(stations_ida[i] - stations_reg[i]);
        if(res <= wait_time[i] && res > 0){
            cout << res << ENDL;
            return 0;
        }
    }



     cout << 0 << ENDL;

    return 0;
}