#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin ("day5.in");
ofstream fout ("day5.out");
typedef long long ll;
typedef pair<ll, ll> pii;

struct Range{
    ll sin, din, r;
};
vector<Range> cv;
vector<ll> event;
vector<pii> v, nv;
string s;

ll get_nr(string &s){
    ll nr=0;
    for (ll i=0; i<s.size(); i++)
        nr=nr*10+s[i]-'0';
    return nr;
}
bool cmp(ll a, ll b){
    return cv[a].sin<cv[b].sin;
}

int main()
{
    fin>>s;
    while (fin>>s && '0'<=s[0] && s[0]<='9'){
        int nr;
        fin>>nr;
        v.pb({get_nr(s), nr+get_nr(s)-1});
    }
    while (fin>>s){
        sort(v.begin(), v.end());
        cv.clear();
        event.clear();

        while (fin>>s && '0'<=s[0] && s[0]<='9'){
            cv.emplace_back();
            cv[cv.size()-1].din=get_nr(s);
            fin>>cv[cv.size()-1].sin>>cv[cv.size()-1].r;

            event.pb(cv.size()-1);
        }
        sort(event.begin(), event.end(), cmp);
        
        for (auto it1:v){
            ll l=it1.fi;
            for (auto it2:event){
                if (cv[it2].sin<=l && it1.se<=cv[it2].sin+cv[it2].r-1){ //(..[..]..)
                    nv.pb({cv[it2].din + l - cv[it2].sin, cv[it2].din + it1.se - cv[it2].sin});
                    l=-1;
                    break;
                }
                else if (cv[it2].sin<=l && l<=cv[it2].sin+cv[it2].r-1){ //(..[..)..]
                    nv.pb({cv[it2].din + l - cv[it2].sin, cv[it2].din + cv[it2].r - 1});
                    l=cv[it2].sin + cv[it2].r;
                }
                else if (l<cv[it2].sin && cv[it2].sin+cv[it2].r-1<it1.se){ //[..(..)..]
                    nv.pb({l, cv[it2].sin-1});
                    nv.pb({cv[it2].din, cv[it2].din + cv[it2].r - 1});
                    l=cv[it2].sin + cv[it2].r;
                }
                else if (l<cv[it2].sin){ //[..(..]..)
                    nv.pb({l, cv[it2].sin-1});
                    nv.pb({cv[it2].din, cv[it2].din+it1.se-cv[it2].sin});
                    l=-1;
                    break;
                }
                else if (it1.se<cv[it2].sin){ //[..]..(..)
                    nv.pb({l, it1.se});
                    l=-1;
                    break;
                }
            }
            if (l!=-1) //(..)..[..]
                nv.pb({l, it1.se});
        }
        v=nv;
        nv.clear();
    }
    
    ll mn=2e9;
    for (auto it:v)
        if (it.fi<mn)
            mn=it.fi;
    fout<<mn;
    return 0;
}
