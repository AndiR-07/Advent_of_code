#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
#define fi first
#define se second
using namespace std;
ifstream fin("day11.in");
ofstream fout("day11.out");
typedef pair<int, int> pii;

vector<string> mat, nmat;
vector<bool> ok;
vector<pii> v;
string s;

int main(){
    while(fin >> s)
        mat.pb(s);
    string nl(mat[0].size(), '.'); //empty line
    for (int i=0; i<mat.size(); i++){ //add empty lines to map
        nmat.pb(mat[i]);
        if (mat[i]==nl)
            nmat.pb(nl);
    }
    for (int j=0; j<nmat[0].size(); j++){
        ok.pb(1);
        for (int i=0; i<nmat.size(); i++)
            if (nmat[i][j]=='#')
                ok.back()=0;
    }

    mat.clear();
    mat.resize(nmat.size());
    for (int i=0; i<nmat.size(); i++) //add empty columns to map
        for (int j=0; j<nmat[i].size(); j++){
            mat[i].pb(nmat[i][j]);
            if (ok[j])
                mat[i].pb('.');
        }
    int n=mat.size(), m=mat[0].size();
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mat[i][j]=='#')
                v.pb({i, j});
    int sol=0;
    for (int i=0; i<v.size(); i++)
        for (int j=i+1; j<v.size(); j++)
            sol+=abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se);
    fout<<sol;
    
    return 0;
}
