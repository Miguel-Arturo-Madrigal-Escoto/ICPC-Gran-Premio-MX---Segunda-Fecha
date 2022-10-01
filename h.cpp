#include <bits/stdc++.h>

#define fore(i,a,b) for(int i = (a), T = (b); i < T; ++i)
#define f first
#define s second
#define ENDL '\n'

using namespace std;

typedef long long lli;

int main(){
    lli n,x,num, aux;
    map<lli,bool> mapa;
    cin>>n>>x;

    
    fore(i,0,n){
        cin>>num;
        aux = num;
        while(num <= x){
            mapa[num] = true;
            num += aux;
        }
    }

    aux = 0;

    for(const auto& m: mapa) aux++;

    cout << aux << ENDL;

    return 0;
}