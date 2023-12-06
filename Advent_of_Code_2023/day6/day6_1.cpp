#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("day6.in");
ofstream fout ("day6.out");
const int Nmax=100;

int t[Nmax], d[Nmax], n, sol=1;
string s;

inline int get_nr(string &s){
    int nr=0;
    for (int i=0; i<s.size(); i++)
        nr=nr*10+s[i]-'0';
    return nr;
}
int main(){
    fin>>s;
    int i=0;
    while (fin>>s && s[0]!='D')
        t[i++]=get_nr(s);
    n=i;
    for (int i=0; i<n; i++)
        fin>>d[i];
    
    for (int i=0; i<n; i++){
        int tcrt=0, solcrt=0;
        for (int j=1; j<t[i]; j++){
            tcrt=(t[i]-j)*j;
            if (tcrt>d[i])
                solcrt++;
        }
        sol*=solcrt;
    }
    fout<<sol;
    return 0;
}
