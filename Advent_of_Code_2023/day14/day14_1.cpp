#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin ("day14.in");
ofstream fout ("day14.out");

vector<string> mat;
vector<int> l;
int n, m, sol;
string s;

int main()
{
    while (fin>>s)
        mat.pb(s);

    n=mat.size(); m=mat[0].size();
    l.resize(m, 0);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mat[i][j]=='#')
                l[j]=i+1;
            else if (mat[i][j]=='O'){
                sol+=n-l[j];
                l[j]=l[j]+1;
            }
        }
    }
    fout<<sol;

    return 0;
}
