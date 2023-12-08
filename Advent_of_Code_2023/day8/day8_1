#include <iostream>
#include <fstream>
#include <unordered_map>

#define fi first
#define se second
using namespace std;
ifstream fin ("day8.in");
ofstream fout ("day8.out");
typedef pair<string, string> ps;

unordered_map<string, ps> mp;
string v, s, s2;

int main(){
    fin>>v;
    while (fin>>s){
        fin>>s2; // '=' character
        fin>>s2;
        s2.pop_back(); // ',' character
        s2.erase(0, 1); // '(' character
        mp[s].fi = s2;

        fin>>mp[s].se;
        mp[s].se.pop_back(); // ')' character
    }
    bool ok=1;
    int i=0;
    s="AAA";
    while (ok){
        if (s=="ZZZ")
            ok=0;
        if (v[i%v.size()]=='L')
            s=mp[s].fi;
        else s=mp[s].se;
        i++;
    }
    fout<<i-1;

    return 0;
}
