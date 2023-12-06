#include <iostream>
#include <vector>
#include <fstream>

#define pb push_back
using namespace std;
ifstream fin ("day3.in");
ofstream fout ("day3.out");
const int Nmax=1e3;

vector<string> v;
string s;
bool ok;
long long sol;
vector<int> mat[Nmax][Nmax];
int main(){
    while(fin>>s)
        v.pb(s);
    for (int i=0; i<v.size(); i++){
        int j=0;
        while (j<v[i].size()){
            if ('0'<=v[i][j] && v[i][j]<='9'){
                int fi=j, nr=0;
                while (j<v[i].size() && '0'<=v[i][j] && v[i][j]<='9'){
                    nr=nr*10+v[i][j]-'0';
                    j++;
                }
                int la=j-1;
                int i2=i-1;
                for (int j2=fi-1; j2<=la+1; j2++)
                    if (0<=i2 && i2<v.size() && 0<=j2 && j2<v[i2].size())
                        if (v[i2][j2]!='.' && !('0'<=v[i2][j] && v[i2][j2]<='9'))
                            mat[i2][j2].pb(nr);
                i2=i+1;
                for (int j2=fi-1; j2<=la+1; j2++)
                    if (0<=i2 && i2<v.size() && 0<=j2 && j2<v[i2].size())
                        if (v[i2][j2]!='.' && !('0'<=v[i2][j] && v[i2][j2]<='9'))
                            mat[i2][j2].pb(nr);
                i2=i;
                int j2=fi-1;
                if (0<=i2 && i2<v.size() && 0<=j2 && j2<v[i2].size())
                    if (v[i2][j2]!='.' && !('0'<=v[i2][j] && v[i2][j2]<='9'))
                        mat[i2][j2].pb(nr);
                j2=la+1;
                if (0<=i2 && i2<v.size() && 0<=j2 && j2<v[i2].size())
                    if (v[i2][j2]!='.' && !('0'<=v[i2][j] && v[i2][j2]<='9'))
                        mat[i2][j2].pb(nr);
            }
            else j++;
        }
    }
    for (int i=0; i<Nmax; i++)
        for (int j=0; j<Nmax; j++){
            if (mat[i][j].size()==2){
                sol+=mat[i][j][0]*mat[i][j][1];
            }
        }
    fout<<sol;

    return 0;
}