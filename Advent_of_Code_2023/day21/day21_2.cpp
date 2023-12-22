#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin ("day21.in");
ofstream fout ("day21.out");
typedef long long ll;
typedef pair<ll, ll> pii;
const ll NrSteps=26501365;

vector<string> mat;
string s;
queue<pii> q;
ll n, sl;
ll vl[]={0, 1, 0, -1}, vc[]={1, 0, -1, 0};
ll nrt[2], nrm[2];

bool inbounds(ll l, ll c){
    return (0<=l && l<n && 0<=c && c<n);
}

int main(){
    while (fin>>s)
        mat.pb(s);
    n=mat.size();
    sl=n/2;

    mat[sl][sl]=0;
    q.push({sl, sl});
    while (!q.empty()){
        auto crt=q.front();
        q.pop();
        
        nrt[mat[crt.fi][crt.se]]++;
        if (abs(crt.fi-sl+crt.se-sl)<=n/2 && mat[crt.fi][crt.se]==1)
            nrm[1]++;
        else if (abs(crt.fi-sl+crt.se-sl)<n/2 && mat[crt.fi][crt.se]==0)
            nrm[0]++;
        for (ll k=0; k<4; k++){
            ll l=crt.fi+vl[k]; 
            ll c=crt.se+vc[k];

            if (inbounds(l, c) && mat[l][c]=='.'){
                mat[l][c]=(mat[crt.fi][crt.se]+1)%2;
                q.push({l, c});
            }
        }
    }
    ll L=(NrSteps-n/2)/n;
    ll ans0=((L+1)*(L+1)-(L+1))*nrt[1]+(L+1)*nrm[1];
    ll ans1=(L*L+L)*nrt[0]-L*nrm[0];
    fout<<ans0+ans1<<'\n';

    return 0;
}
