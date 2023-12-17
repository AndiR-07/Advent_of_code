#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define pb push_back
using namespace std;
ifstream fin("day17.in");
ofstream fout("day17.out");

string s;
vector<string> mat;
vector<vector<int>> hl[4][3];

struct position{
    int dir, steps, x, y;
};
struct cmp{
    bool operator()(position a, position b){
        return hl[a.dir][a.steps][a.x][a.y]>hl[b.dir][b.steps][b.x][b.y];
    }
};
priority_queue <position, vector<position>, cmp> pq;
int n, m, vl[]={-1, 0, 1, 0}, vc[]={0, 1, 0, -1};

bool inbounds(int x, int y){
    return (0<=x && x<n && 0<=y && y<m);
}
int main(){
    while (fin>>s)
        mat.pb(s);
    n=mat.size(); m=mat[0].size();
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            mat[i][j]-='0';
    
    for (int i=0; i<4; i++)
        for (int j=0; j<3; j++)
            hl[i][j].resize(n, vector<int>(m, 1e9));
    hl[1][0][0][1]=mat[0][1];
    hl[2][0][1][0]=mat[1][0];
    pq.push({1, 0, 0, 1});
    pq.push({2, 0, 1, 0});

    int sol, ok=1;
    while (ok && !pq.empty()){
        position crt=pq.top();
        pq.pop();

        if (crt.x==n-1 && crt.y==m-1){
            sol=hl[crt.dir][crt.steps][crt.x][crt.y];
            ok=0;
            break;
        }

        if (crt.steps!=2){
            int l=crt.x+vl[crt.dir], c=crt.y+vc[crt.dir];
            if (inbounds(l, c) && hl[crt.dir][crt.steps+1][l][c]>hl[crt.dir][crt.steps][crt.x][crt.y]+mat[l][c]){
                hl[crt.dir][crt.steps+1][l][c]=hl[crt.dir][crt.steps][crt.x][crt.y]+mat[l][c];
                pq.push({crt.dir, crt.steps+1, l, c});
            }
        }
        for (int k=0; k<4; k++)
            if (k!=crt.dir && abs(k-crt.dir)!=2){
                int l=crt.x+vl[k], c=crt.y+vc[k];
                if (inbounds(l, c) && hl[k][0][l][c]>hl[crt.dir][crt.steps][crt.x][crt.y]+mat[l][c]){
                    hl[k][0][l][c]=hl[crt.dir][crt.steps][crt.x][crt.y]+mat[l][c];
                    pq.push({k, 0, l, c});
                }
            }
    }
    fout<<sol;

    return 0;
}
