#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin("day19.in");
ofstream fout("day19.out");
typedef long long ll;
typedef pair<int, int> pii;
const int Vmax=4e3;

string s;
unordered_map<string, int> mp;
int cnv[256];
struct condition{
    bool cnd;
    int t, val;
    string nxtflow;
};
vector<vector<condition>> wf;
ll sol;
struct interval{
    pii v[4];
};

void dfs(string workflow, interval crt){
    if (workflow=="A"){
        ll p=1;
        for (int i=0; i<4; i++)
            p*=(crt.v[i].se-crt.v[i].fi+1);
        sol+=p;
        return;
    }
    if (workflow=="R")
        return;
    int id=mp[workflow];
    for (auto it:wf[id]){
        if (it.val==0){
            dfs(it.nxtflow, crt);
            return;
        }
        interval nxt=crt;
        if (!it.cnd){
            if (crt.v[it.t].se<it.val){
                dfs(it.nxtflow, crt);
                return;
            }
            else{
                nxt.v[it.t].se=it.val-1;
                crt.v[it.t].fi=max(crt.v[it.t].fi, it.val);
            }
        }
        else{
            if (crt.v[it.t].fi>it.val){
                dfs(it.nxtflow, crt);
                return;
            }
            else{
                nxt.v[it.t].fi=it.val+1;
                crt.v[it.t].se=min(crt.v[it.t].se, it.val);
            }
        }
        if (nxt.v[it.t].fi<=nxt.v[it.t].se)
            dfs(it.nxtflow, nxt);
        if (crt.v[it.t].fi>crt.v[it.t].se)
            return;
        
    }
}

int main(){
    cnv['m']=1; cnv['a']=2; cnv['s']=3;
    cnv['>']=1;
    int id=0;
    while (fin>>s)
        if (s[0]!='{'){ // procces a workflow
            string name;
            int i=0;
            while (s[i]!='{')
                name+=s[i++];
            mp[name]=id;

            i++;
            wf.emplace_back();
            while (i!=s.size()){ // procces a condition
                string crt;
                while (s[i]!=',' && s[i]!='}')
                    crt+=s[i++];

                if (i+1==s.size())
                    wf[id].pb({0, 0, 0, crt});
                else{
                    int t=cnv[crt[0]];
                    bool cnd=cnv[crt[1]];
                    int i=2, val=0;
                    while (crt[i]!=':')
                        val=val*10+crt[i++]-'0';
                    string nxtflow;
                    i++;
                    while (i!=crt.size())
                        nxtflow+=crt[i++];
                    wf[id].pb({cnd, t, val, nxtflow});
                }
                //cout<<wf[id].back().t<<' '<<wf[id].back().cnd<<' '<<wf[id].back().val<<' '<<wf[id].back().nxtflow<<'\n';
                
                i++;
            }
            //cout<<'\n';
            id++;
        }
        else break;
    interval crt={{{1, Vmax}, {1, Vmax}, {1, Vmax}, {1, Vmax}}};
    dfs("in", crt);
        
    fout<<sol;

    return 0;
}
