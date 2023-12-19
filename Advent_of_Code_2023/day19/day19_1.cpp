#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#define pb push_back
using namespace std;
ifstream fin("day19.in");
ofstream fout("day19.out");

string s;
unordered_map<string, int> mp;
vector<int> v[4];
int cnv[256];
struct condition{
    bool cnd;
    int t, val;
    string nxtflow;
};
vector<vector<condition>> wf;
int sol;

int main(){
    cnv['m']=1; cnv['a']=2; cnv['s']=3;
    cnv['>']=1;
    int id=0;
    while (fin>>s){
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
        else{ // procces a part
            int i=3;
            for (int j=0; j<4; j++){
                int val=0;
                while (s[i]!=',' && s[i]!='}')
                    val=val*10+s[i++]-'0';
                v[j].pb(val);
                //cout<<v[j].back()<<' ';
                i+=3;
            }
            //cout<<'\n';
            int crtid=mp["in"], ok=0;
            string nxtflow;
            while (ok==0){
                for (auto it:wf[crtid]){
                    if (it.val==0){
                        nxtflow=it.nxtflow;
                        break;
                    }
                    else if (!it.cnd){
                        if (v[it.t].back()<it.val){
                            nxtflow=it.nxtflow;
                            break;
                        }
                    }
                    else if (v[it.t].back()>it.val){
                            nxtflow=it.nxtflow;
                            break;
                        }
                        
                }
                if (nxtflow=="A")
                    ok=1;
                else if (nxtflow=="R")
                    ok=2;
                else crtid=mp[nxtflow];
            }
            if (ok==1)
                for (int i=0; i<4; i++)
                    sol+=v[i].back();
        }
    }
    fout<<sol;

    return 0;
}
