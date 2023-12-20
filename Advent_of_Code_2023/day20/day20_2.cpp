#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

#define pb push_back
using namespace std;
ifstream fin ("day20.in");
ofstream fout ("day20.out");
typedef long long ll;
const int Tmax=1000;

string s, s2;
struct module{
    int t=0;
    vector<string> ad;
    int crton=0;
    unordered_map<string, bool> lm; //for conjunction modules
    bool on=0; // for flip-flops modules
};
unordered_map<string, module> mp;
string l4[]={"kk", "xc", "sk", "vt"}; // the 4 modules that must be on simultaneously in order to turn on the rx module
ll sum[2], period[4];
struct pulse{
    string ant, s;
    int t;
};
queue <pulse> q; // 0 for low, 1 for high


int main(){
    while (fin>>s){
        if (s[0]=='%'){
            s=s.substr(1);
            mp[s].t=1;
        }
        else if (s[0]=='&'){
            s=s.substr(1);
            mp[s].t=2;
        }
        fin>>s2;
        while (fin>>s2){
            bool ok=0;
            if (s2.back()==',')
                s2.pop_back();
            else ok=1;

            mp[s].ad.pb(s2);
            mp[s2].lm[s]=0;
            if (ok)
                break;
        }
    }
    bool ok=1;
    int i=0;
    while (ok){
        sum[0]++; // button pressed
        q.push({"button", "broadcaster", 0});
        while (!q.empty()){
            auto crt=q.front();
            q.pop();
            if (crt.s=="broadcaster")
                for (auto it:mp[crt.s].ad){
                    q.push({crt.s, it, 0});
                    sum[0]++;
                }
            else if (mp[crt.s].t==1){
                if (crt.t==0){
                    mp[crt.s].on=!mp[crt.s].on;
                    for (auto it:mp[crt.s].ad){
                        q.push({crt.s, it, mp[crt.s].on});
                        sum[mp[crt.s].on]++;
                    }
                }
            }
            else{
                if (mp[crt.s].lm[crt.ant]<crt.t)
                    mp[crt.s].crton++;
                else if (mp[crt.s].lm[crt.ant]>crt.t)
                    mp[crt.s].crton--;
                mp[crt.s].lm[crt.ant]=crt.t;
                if (mp[crt.s].crton==mp[crt.s].lm.size())
                    for (auto it:mp[crt.s].ad){
                        q.push({crt.s, it, 0});
                        sum[0]++;
                    }
                else
                    for (auto it:mp[crt.s].ad){
                        q.push({crt.s, it, 1});
                        sum[1]++;
                    }
            }
            if (crt.t==0){
                for (int j=0; j<4; j++)
                    if (l4[j]==crt.s && period[j]==0)
                        period[j]=i+1;
                ok=0;
                for (int j=0; j<4; j++)
                    if (period[j]==0)
                        ok=1;
            }
        }
        i++;
    }
    ll p1=period[0]*period[1];
    ll p2=period[2]*period[3];
    fout<<p1*p2/__gcd(p1/__gcd(period[0], period[1]), p2/__gcd(period[2], period[3]));

    return 0;
}
