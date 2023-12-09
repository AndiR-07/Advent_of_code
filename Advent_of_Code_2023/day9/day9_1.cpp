#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin ("day9.in");
ofstream fout ("day9.out");
typedef long long ll;

string s;
ll sol;
vector<ll> v;

int main(){
    while (getline(fin, s)){
        ll i=0, sum=0;
        while (i<s.size()){
            ll nr=0, sgn=1;
            if (s[i]=='-'){
                sgn=-1;
                i++;
            }
            while (i<s.size() && s[i]!=' '){
                nr=nr*10+sgn*(s[i]-'0');
                i++;
            }
            v.push_back(nr);
            nr=0;
            while (i<s.size() && s[i]==' ')
                i++;
        }
        bool ok=1;
        while (ok){
            sum+=v.back();
            ok=0;
            for (ll i=0; i<v.size()-1; i++){
                v[i]=v[i+1]-v[i];
                if (v[i]!=0)
                    ok=1;
            }
            v.pop_back();
        }
        sol+=sum;
        v.clear();
    }
    fout<<sol;

    return 0;
}
