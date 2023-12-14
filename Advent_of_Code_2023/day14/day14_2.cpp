#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin ("day14.in");
ofstream fout ("day14.out");
const int NrCycles=1000000000;

vector<string> mat;
vector<vector<string>> mem;
vector<int> l;
int n, m, sol;
string s;

int main()
{
    while (fin>>s)
        mat.pb(s);

    n=mat.size(); m=mat[0].size();
    int in=-1, r=0;
    while(in==-1){
        // north
        l.clear();
        l.resize(m, 0);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (mat[i][j]=='#')
                    l[j]=i+1;
                else if (mat[i][j]=='O'){
                    mat[i][j]='.';
                    mat[l[j]][j]='O';
                    l[j]=l[j]+1;
                }
        // west
        l.clear();
        l.resize(n, 0);
        for (int j=0; j<m; j++)
            for (int i=0; i<n; i++)
                if (mat[i][j]=='#')
                    l[i]=j+1;
                else if (mat[i][j]=='O'){
                    mat[i][j]='.';
                    mat[i][l[i]]='O';
                    l[i]=l[i]+1;
                }
        // south
        l.clear();
        l.resize(m, n-1);
        for (int i=n-1; i>=0; i--)
            for (int j=0; j<m; j++)
                if (mat[i][j]=='#')
                    l[j]=i-1;
                else if (mat[i][j]=='O'){
                    mat[i][j]='.';
                    mat[l[j]][j]='O';
                    l[j]=l[j]-1;
                }
        // east
        l.clear();
        l.resize(n, m-1);
        for (int j=m-1; j>=0; j--)
            for (int i=0; i<n; i++)
                if (mat[i][j]=='#')
                    l[i]=j-1;
                else if (mat[i][j]=='O'){
                    mat[i][j]='.';
                    mat[i][l[i]]='O';
                    l[i]=l[i]-1;
                }
        // check
        for (int i=0; i<mem.size(); i++)
            if (mat==mem[i]){
                in=i;
                r=mem.size()-i;
                break;
            }
        mem.pb(mat);
    }
    int ans=in+(NrCycles-1-in)%r;

    int sol=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mem[ans][i][j]=='O')
                sol+=n-i;
    fout<<sol;

    return 0;
}
