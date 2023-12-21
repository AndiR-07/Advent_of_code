#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define pb push_back
using namespace std;
ifstream fin ("day21.in");
ofstream fout ("day21.out");
const int NrSteps=64;

vector<string> mat;
string s;
struct pos{
    int l, c, d;
};
queue<pos> q;
int n, m, sl, sc, sol;
int vl[]={0, 1, 0, -1}, vc[]={1, 0, -1, 0};

bool inbounds(int l, int c){
    return (0<=l && l<n && 0<=c && c<m);
}

int main(){
    while (fin>>s)
        mat.pb(s);
    n=mat.size(); m=mat[0].size();
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mat[i][j]=='S'){
                sl=i;
                sc=j;
            }
    mat[sl][sc]=0;
    q.push({sl, sc, 0});
    while (!q.empty() && q.front().d<=NrSteps){
        auto crt=q.front();
        q.pop();
        if (crt.d%2==0)
            sol++;
        for (int k=0; k<4; k++){
            int l=crt.l+vl[k]; 
            int c=crt.c+vc[k];

            if (inbounds(l, c) && mat[l][c]=='.'){
                mat[l][c]=(crt.d+1)%2;
                q.push({l, c, crt.d+1});
            }
        }
    }
    fout<<sol;

    return 0;
}
