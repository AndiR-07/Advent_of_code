#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin("day18.in");
ofstream fout("day18.out");
typedef long long ll;
typedef pair<ll, ll> pii;

string s;

vector<pii> v;
ll cnv[256], vl[]={0, 1, 0, -1}, vc[]={1, 0, -1, 0};
ll sol, bound;

//Determinant of 3 points
ll det(pii a, pii b, pii c){
    return (b.fi-a.fi)*(c.se-a.se)-(c.fi-a.fi)*(b.se-a.se);
}

int main(){
    for (ll i=0; i<=9; i++)
        cnv['0'+i] = i;
    for (ll i=0; i<='z'-'a'; i++)
        cnv['a'+i] = i+10;

    v.pb({0, 0});
    ll x=0, y=0;
    while (fin>>s){
        fin>>s>>s;

        ll val=0;
        for (ll i=2; i<=6; i++)
            val=val*16+cnv[s[i]];
        bound+=val;
        x+=vl[cnv[s[7]]]*val;
        y+=vc[cnv[s[7]]]*val;
        v.pb({x, y});
    }
    v.pb({0, 0});

    //Shoelace formula (Area of a polygon)
    for (ll i=0; i<v.size()-1; i++)
        sol+=det(v[0], v[i], v[i+1]);
    sol=abs(sol)/2;
    //Pick's theorem
    fout<<sol+1+bound/2;

    return 0;
}
