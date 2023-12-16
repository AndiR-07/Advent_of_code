#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin("day16.in");
ofstream fout("day16.out");

string s;
vector<string> mat;
vector <vector<bool>> fr[4];
int sol, n, m, vl[]={-1, 0, 1, 0}, vc[]={0, 1, 0, -1};

bool inbounds(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}
void dfs(int x, int y, int dir){
    int dir2=-1;
    fr[dir][x][y]=1;
    if (mat[x][y]=='/')
        if (dir==0)
            dir=1;
        else if (dir==1)
            dir=0;
        else if (dir==2)
            dir=3;
        else dir=2;
    else if (mat[x][y]=='\\')
        if (dir==0)
            dir=3;
        else if (dir==1)
            dir=2;
        else if (dir==2)
            dir=1;
        else dir=0;
    else if (mat[x][y]=='-'){
        if (dir==0 || dir==2){
            dir=1;
            dir2=3;
        }
    }
    else if (mat[x][y]=='|'){
        if (dir==1 || dir==3){
            dir=0;
            dir2=2;
        }
    }
    int l=x+vl[dir], c=y+vc[dir];
    if (inbounds(l, c) && fr[dir][l][c]==0)
        dfs(l, c, dir);
    if (dir2!=-1){
        l=x+vl[dir2], c=y+vc[dir2];
        if (inbounds(l, c) && fr[dir2][l][c]==0)
            dfs(l, c, dir2);
    }
}

int main(){
    while (fin>>s)
        mat.pb(s);

    n=mat.size(), m=mat[0].size();
    for (int i=0; i<4; i++)
        fr[i].resize(n, vector<bool>(m, 0));
    dfs(0, 0, 1);

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            bool ok=0;
            for (int k=0; k<4; k++)
                if (fr[k][i][j])
                    ok=1;
            sol+=ok;
        }
    fout<<sol;

    return 0;
}
