#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin("day23.in");
ofstream fout("day23.out");

vector<string> mat;
vector<vector<bool>> v;
string s;
int vl[]={0, 1, 0, -1}, vc[]={1, 0, -1, 0};
vector<vector<int>> dist;
char inv[]={'<', '^', '>', 'v'};
int n, m, l, c;

bool inbounds(int x, int y){
    return (0<=x && x<n && 0<=y && y<m);
}
void dfs(int x, int y, int px, int py){
    if (dist[x][y]!=0)
        return;
    dist[x][y]=1;
    for (int k=0; k<4; k++){
        int l=x+vl[k], c=y+vc[k];
        if (inbounds(l, c) && mat[l][c]!='#' && mat[l][c]!=inv[k] && (px!=l || py!=c)){
            dfs(l, c, x, y);
            dist[x][y]=max(dist[x][y], dist[l][c]+1);
        }
    }
}

int main(){
    while (fin>>s)
        mat.pb(s);
    n=mat.size(); m=mat[0].size();
    dist.resize(n, vector<int>(m, 0));
    for (int j=0; j<m; j++)
        if (mat[0][j]=='.')
            c=j;
    dfs(0, c, -1, -1);
    cout<<dist[0][c]-1;

    return 0;
}
