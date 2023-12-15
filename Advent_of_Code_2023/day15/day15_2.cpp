#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin ("day15.in");
ofstream fout ("day15.out");
const int B=17, Mod=256;

string s, crt;
int sol;
struct lens{
    int ind=-1, val, pos=-1;
};
unordered_map <string, lens> mp;
vector <int> v[Mod];
vector <string> cnv;

int get_hash(string s){
    int ans=0;
    for (auto it:s)
        ans=(ans+it)*B%Mod;
    return ans;
}

int main(){
    fin>>s;
    int i=0, crtind=0;
    while (i<s.size()){
        crt.clear();
        int sum=0;
        while (s[i]!='-' && s[i]!='=')
            crt.pb(s[i++]);
        int hash=get_hash(crt);
        if (s[i]=='-'){
            if (mp[crt].pos!=-1){
                v[hash][mp[crt].pos]=-1;
                mp[crt].pos=-1;
            }
            i++;
        }
        else{
            int nr=0;
            i++;
            while (i<s.size() && s[i]!=',')
                nr=nr*10+s[i++]-'0';
            mp[crt].val=nr;
            if (mp[crt].pos==-1){
                if (mp[crt].ind==-1){
                    mp[crt].ind=crtind++;
                    cnv.pb(crt);
                }
                v[hash].pb(mp[crt].ind);
                mp[crt].pos=v[hash].size()-1;
            }
        }
        i++;
    }
    for (int k=0; k<Mod; k++){
        int pos=1;
        for (int i=0; i<v[k].size(); i++)
            if (v[k][i]!=-1)
                mp[cnv[v[k][i]]].pos=pos++;
    }
    for (auto it:mp)
        if (it.se.pos!=-1)
            sol+=(1+get_hash(it.fi))*it.se.pos*it.se.val;
    fout<<sol;

    return 0;
}
