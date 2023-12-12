#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin ("day12.in");
ofstream fout ("day12.out");

string s, s2;
vector <int> v, pos;
int sum, sol;

inline bool check(){
    vector<int> aux;
    int j=0; 
    while (j<s.size() && s[j]=='.')
        j++;
    while (j<s.size()){
        int nr=0;
        while (j<s.size() && s[j]=='#'){
            nr++;
            j++;
        }
        aux.pb(nr);
        while (j<s.size() && s[j]=='.')
            j++;
    }
    return aux==v;
}
void bkt(int p){
    if (p==pos.size()){
        if (check())
            sum++;
        return;
    }
    s[pos[p]]='.';
    bkt(p+1);
    s[pos[p]]='#';
    bkt(p+1);
}

int main(){
    while (fin>>s){
        // get the position
        for (int i=0; i<s.size(); i++)
            if (s[i]=='?')
                pos.pb(i);

        // get the numbers
        fin>>s2;
        int j=0;
        while (j<s2.size()){
            int nr=0;
            while (j<s2.size() && s2[j]!=','){
                nr=nr*10+s2[j]-'0';
                j++;
            }
            v.pb(nr);
            j++;
        }

        // get all possible combinations
        sum=0;
        bkt(0);
        sol+=sum;
        v.clear();
        pos.clear();
    }
    fout<<sol;

    return 0;
}
