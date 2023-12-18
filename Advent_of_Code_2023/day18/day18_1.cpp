#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("day18.in");
ofstream fout("day18.out");
typedef pair<int, int> pii;
const int Nmax=6e2+5;

struct step{
    int dir, val;
    string s;
};
vector <step> v;

int cnv[256], mnx, mxx, mny, mxy, i, j, vl[]={-1, 0, 1, 0}, vc[]={0, 1, 0, -1}, addx, addy, x, y, sum=1;
bool mat[Nmax][Nmax];
char ch;
queue <pii> q;

bool inbounds(int x, int y){
    return (0<=x && x<Nmax && 0<=y && y<Nmax);
}

int main(){
    cnv['U']=0; cnv['R']=1; cnv['D']=2; cnv['L']=3;
    while (fin>>ch){
        v.emplace_back();
        v.back().dir=cnv[ch];
        fin>>v.back().val;
        fin>>v.back().s;

        i+=v.back().val*vl[v.back().dir];
        j+=v.back().val*vc[v.back().dir];
        mnx=min(mnx, i); mxx=max(mxx, i);
        mny=min(mny, j); mxy=max(mxy, j);
    }
    addx=-mnx+1, addy=-mny+1;
    mat[x+addx][y+addy]=1;
    for (auto it:v)
        for (int i=1; i<=it.val; i++){
            x+=vl[it.dir];
            y+=vc[it.dir];
            mat[x+addx][y+addy]=1;
        }
    mat[0][0]=1;
    q.push({0, 0});
    while (!q.empty()){
        pii crt=q.front();
        q.pop();
        for (int k=0; k<4; k++){
            int l=crt.first+vl[k], c=crt.second+vc[k];
            if (inbounds(l, c) && mat[l][c]==0){
                mat[l][c]=1;
                q.push({l, c});
                sum++;
            }
        }
    }
    fout<<Nmax*Nmax-sum;

    return 0;
}
