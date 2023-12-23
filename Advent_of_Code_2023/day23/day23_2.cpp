#include <iostream>
#include <fstream>
#include <vector>

#pragma GCC optimise("O3")

#define pb push_back
using namespace std;
ifstream fin("day23.in");
ofstream fout("day23.out");

vector<string> mat;
string s;
short vl[]={0, -1, 0, 1}, vc[]={-1, 0, 1, 0};
short sol;
vector<vector<bool>> vis;
short n, m, l, c;

bool inbounds(short x, short y){
    return (0<=x && x<n && 0<=y && y<m);
}
void dfs(short x, short y, short dist){
    vis[x][y]=1;
    if (x==n-1)
        if (dist>sol){
            sol=dist;
            cout<<sol<<'\n';
        }
    for (short k=0; k<4; k++){
        short l=x+vl[k], c=y+vc[k];
        if (inbounds(l, c) && mat[l][c]!='#' && !vis[l][c])
            dfs(l, c,dist+1);
    }
    vis[x][y]=0;
}

int main(){
    while (fin>>s)
        mat.pb(s);
    n=mat.size(); m=mat[0].size();
    vis.resize(n, vector<bool>(m, 0));
    for (int j=0; j<m; j++)
        if (mat[0][j]=='.')
            c=j;
    dfs(0, c, 0);
    fout<<sol;

    return 0;
}
