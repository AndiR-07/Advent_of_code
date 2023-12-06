//the winning distances are achived in a time interval so we can 
//binary search the first winning situation and the last one

#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("day6.in");
ofstream fout ("day6.out");
typedef long long ll;
const int Nmax=100;

ll t, d, n;
string s, sf;

inline ll get_nr(string &s){
    ll nr=0;
    for (int i=0; i<s.size(); i++)
        nr=nr*10+s[i]-'0';
    return nr;
}
int main(){
    fin>>s;
    while (fin>>s && s[0]!='D')
        sf+=s;
    t=get_nr(sf);
    sf.clear();
    while (fin>>s)
        sf+=s;
    d=get_nr(sf);
    
    //binary search for the first winning situation
    ll l=1, r=t, mij, sol1=-1;
    while (l<=r){
        mij=(l+r)/2;
        if ((t-mij)*mij>d){
            sol1=mij;
            r=mij-1;
        }
        else l=mij+1;
    }
    //binary search for the last winning situation
    ll sol2; l=1, r=t;
    while (l<=r){
        mij=(l+r)/2;
        if ((t-mij)*mij>d){
            sol2=mij;
            l=mij+1;
        }
        else r=mij-1;
    }
    if (sol1==-1)
        fout<<0;
    else fout<<sol2-sol1+1;

    return 0;
}
