//Really weird problem, without examination of the input file, it is probably np-hard

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
using namespace std;
ifstream fin ("day8.in");
ofstream fout ("day8.out");
typedef pair<string, string> ps;
typedef unsigned long long ll;

unordered_map<string, ps> mp;
vector<string> crt;
string v, s, s2;

int main(){
    fin>>v;
    while (fin>>s){
        if (s[s.size()-1]=='A')
            crt.pb(s);
        fin>>s2; // '=' character
        fin>>s2;
        s2.pop_back(); // ',' character
        s2.erase(0, 1); // '(' character
        mp[s].fi = s2;

        fin>>mp[s].se;
        mp[s].se.pop_back(); // ')' character
    }
    ll lcm=1;
    for (int j=0; j<crt.size(); j++){
        bool ok=1;
        ll i=0;
        while (ok){
            if (crt[j][crt[j].size()-1]=='Z')
                ok=0;

            if (v[i%v.size()]=='L')
                crt[j]=mp[crt[j]].fi;
            else crt[j]=mp[crt[j]].se;
            i++;
        }
        i--;
        lcm=lcm*i/__gcd(lcm, i);
        cout<<lcm<<'\n';
    }
    fout<<lcm;

    return 0;
}
