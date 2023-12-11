#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin("day11.in");
ofstream fout("day11.out");
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Vadd=1000000-1;

vector<string> mat;
vector<ll> spel, spec;
vector<pii> v;
string s;

int main(){
    while(fin >> s)
        mat.pb(s);

    ll n=mat.size(), m=mat[0].size();
    string el(m, '.'); // empty line
    spel.resize(n, 0); spec.resize(m, 1);

    for (ll i=0; i<n; i++)
        if (mat[i]==el)
            spel[i]=1;
    for (ll j=0; j<m; j++)
        for (ll i=0; i<n; i++)
            if (mat[i][j]!='.')
                spec[j]=0;

    for (ll i=1; i<n; i++)
        spel[i]+=spel[i-1];
    for (ll j=1; j<m; j++)
        spec[j]+=spec[j-1];
    
    for (ll i=0; i<n; i++)
        for (ll j=0; j<m; j++)
            if (mat[i][j]=='#')
                v.pb({i, j});
    for (ll i=0; i<v.size(); i++){
        v[i].fi+=spel[v[i].fi]*Vadd;
        v[i].se+=spec[v[i].se]*Vadd;
    }

    ll sol=0;
    for (ll i=0; i<v.size(); i++)
        for (ll j=i+1; j<v.size(); j++)
            sol+=abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se);
    fout<<sol;

    return 0;
}
