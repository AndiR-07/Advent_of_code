#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>

#define pb push_back
using namespace std;
ifstream fin ("day10.in");
ofstream fout("day10.out");

vector<string> mat;
vector<vector<int>> dist;
string s;
int n, m, si, sj, vl[]={-1, 1, 0, 0}, vc[]={0, 0, -1, 1};
//int cnv[256];
unordered_set<char> dir[4];

struct info{
    int l, c, pl, pc;
};
queue <info> q;

bool inb(int l, int c){
    return (l>=0 && l<n && c>=0 && c<m);
}

int main(){
     /*
    '|' up - down
    '-' left - right
    'L' up - right
    'J' up - left
    '7' down - left
    'F' down - right
    */

    dir[0].insert({'|', '7', 'F'}); // 0. can connect up -> '|', '7', 'F'
    dir[1].insert({'|', 'J', 'L'}); // 1. can connect down -> '|', 'J', 'L'
    dir[2].insert({'-', 'F', 'L'}); // 2. can connect left -> '-', 'F', 'L'
    dir[3].insert({'-', '7', 'J'}); // 3. can connect right -> '-', '7', 'J'

    while (fin>>s)
        mat.push_back(s);
    n=mat.size();
    m=mat[0].size();
    dist.resize(n, vector<int>(m, 0));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mat[i][j]=='S'){
                si=i; 
                sj=j;
            }
    q.push({si, sj, 0, 0});
    int sol=0;
    while (!q.empty()){
        info crt=q.front();
        int l=crt.l, c=crt.c, pl=crt.pl, pc=crt.pc;
        q.pop();

        if (mat[l][c]=='S'){
            for (int i=0; i<4; i++)
                if (inb(l+vl[i], c+vc[i]) && dir[i].find(mat[l+vl[i]][c+vc[i]])!=dir[i].end()){
                    q.push({l+vl[i], c+vc[i], l, c});
                    dist[l+vl[i]][c+vc[i]]=1;
                }
        }
        else if (mat[l][c]=='|'){
            if (pl-1==l){
                if (inb(l+vl[0], c+vc[0]) && dir[0].find(mat[l+vl[0]][c+vc[0]])!=dir[0].end()){
                    if (dist[l+vl[0]][c+vc[0]]!=0){
                        sol=max(dist[l][c], dist[l+vl[0]][c+vc[0]]);
                        break;
                    }
                    q.push({l+vl[0], c+vc[0], l, c});
                    dist[l+vl[0]][c+vc[0]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[1], c+vc[1]) && dir[1].find(mat[l+vl[1]][c+vc[1]])!=dir[1].end()){
                    if (dist[l+vl[1]][c+vc[1]]!=0){
                        sol=max(dist[l][c], dist[l+vl[1]][c+vc[1]]);
                        break;
                    }
                    q.push({l+vl[1], c+vc[1], l, c});
                    dist[l+vl[1]][c+vc[1]]=dist[l][c]+1;
                }
            }
        }
        else if (mat[l][c]=='-'){
            if (pc-1==c){
                if (inb(l+vl[2], c+vc[2]) && dir[2].find(mat[l+vl[2]][c+vc[2]])!=dir[2].end()){
                    if (dist[l+vl[2]][c+vc[2]]!=0){
                        sol=max(dist[l][c], dist[l+vl[2]][c+vc[2]]);
                        break;
                    }
                    q.push({l+vl[2], c+vc[2], l, c});
                    dist[l+vl[2]][c+vc[2]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[3], c+vc[3]) && dir[3].find(mat[l+vl[3]][c+vc[3]])!=dir[3].end()){
                    if (dist[l+vl[3]][c+vc[3]]!=0){
                        sol=max(dist[l][c], dist[l+vl[3]][c+vc[3]]);
                        break;
                    }
                    q.push({l+vl[3], c+vc[3], l, c});
                    dist[l+vl[3]][c+vc[3]]=dist[l][c]+1;
                }
            }
        }
        else if (mat[l][c]=='L'){
            if (pl+1==l){
                if (inb(l+vl[3], c+vc[3]) && dir[3].find(mat[l+vl[3]][c+vc[3]])!=dir[3].end()){
                    if (dist[l+vl[3]][c+vc[3]]!=0){
                        sol=max(dist[l][c], dist[l+vl[3]][c+vc[3]]);
                        break;
                    }
                    q.push({l+vl[3], c+vc[3], l, c});
                    dist[l+vl[3]][c+vc[3]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[0], c+vc[0]) && dir[0].find(mat[l+vl[0]][c+vc[0]])!=dir[0].end()){
                    if (dist[l+vl[0]][c+vc[0]]!=0){
                        sol=max(dist[l][c], dist[l+vl[0]][c+vc[0]]);
                        break;
                    }
                    q.push({l+vl[0], c+vc[0], l, c});
                    dist[l+vl[0]][c+vc[0]]=dist[l][c]+1;
                }
            }
        }
        else if (mat[l][c]=='J'){
            if (pl+1==l){
                if (inb(l+vl[2], c+vc[2]) && dir[2].find(mat[l+vl[2]][c+vc[2]])!=dir[2].end()){
                    if (dist[l+vl[2]][c+vc[2]]!=0){
                        sol=max(dist[l][c], dist[l+vl[2]][c+vc[2]]);
                        break;
                    }
                    q.push({l+vl[2], c+vc[2], l, c});
                    dist[l+vl[2]][c+vc[2]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[0], c+vc[0]) && dir[0].find(mat[l+vl[0]][c+vc[0]])!=dir[0].end()){
                    if (dist[l+vl[0]][c+vc[0]]!=0){
                        sol=max(dist[l][c], dist[l+vl[0]][c+vc[0]]);
                        break;
                    }
                    q.push({l+vl[0], c+vc[0], l, c});
                    dist[l+vl[0]][c+vc[0]]=dist[l][c]+1;
                }
            }
        }
        else if (mat[l][c]=='7'){
            if (pl-1==l){
                if (inb(l+vl[2], c+vc[2]) && dir[2].find(mat[l+vl[2]][c+vc[2]])!=dir[2].end()){
                    if (dist[l+vl[2]][c+vc[2]]!=0){
                        sol=max(dist[l][c], dist[l+vl[2]][c+vc[2]]);
                        break;
                    }
                    q.push({l+vl[2], c+vc[2], l, c});
                    dist[l+vl[2]][c+vc[2]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[1], c+vc[1]) && dir[1].find(mat[l+vl[1]][c+vc[1]])!=dir[1].end()){
                    if (dist[l+vl[1]][c+vc[1]]!=0){
                        sol=max(dist[l][c], dist[l+vl[1]][c+vc[1]]);
                        break;
                    }
                    q.push({l+vl[1], c+vc[1], l, c});
                    dist[l+vl[1]][c+vc[1]]=dist[l][c]+1;
                }
            }
        }
        else if (mat[l][c]=='F'){
            if (pl-1==l){
                if (inb(l+vl[3], c+vc[3]) && dir[3].find(mat[l+vl[3]][c+vc[3]])!=dir[3].end()){
                    if (dist[l+vl[3]][c+vc[3]]!=0){
                        sol=max(dist[l][c], dist[l+vl[3]][c+vc[3]]);
                        break;
                    }
                    q.push({l+vl[3], c+vc[3], l, c});
                    dist[l+vl[3]][c+vc[3]]=dist[l][c]+1;
                }
            }
            else{
                if (inb(l+vl[1], c+vc[1]) && dir[1].find(mat[l+vl[1]][c+vc[1]])!=dir[1].end()){
                    if (dist[l+vl[1]][c+vc[1]]!=0){
                        sol=max(dist[l][c], dist[l+vl[1]][c+vc[1]]);
                        break;
                    }
                    q.push({l+vl[1], c+vc[1], l, c});
                    dist[l+vl[1]][c+vc[1]]=dist[l][c]+1;
                }
            }
        }
    }

    dist[si][sj]=1;
    bool fr[4]={};
    for (int i=0; i<4; i++)
        if (inb(si+vl[i], sj+vc[i]) && dist[si+vl[i]][sj+vc[i]]!=0)
            fr[i]=1;
    if (fr[0] && fr[1])
        mat[si][sj]='|';
    else if (fr[2] && fr[3])
        mat[si][sj]='-';
    else if (fr[0] && fr[3])
        mat[si][sj]='L';
    else if (fr[0] && fr[2])
        mat[si][sj]='J';
    else if (fr[1] && fr[2])
        mat[si][sj]='7';
    else if (fr[1] && fr[3])
        mat[si][sj]='F';

    sol=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int nrint=0;
            if (dist[i][j]==0){
                int k=1;
                while (inb(i+k, j+k)){
                    if (dist[i+k][j+k]!=0){
                        if (mat[i+k][j+k]=='|' || mat[i+k][j+k]=='-' || mat[i+k][j+k]=='F' || mat[i+k][j+k]=='J')
                            nrint++;
                        else if (mat[i+k][j+k]=='L')
                            nrint+=2;
                    }
                    k++;
                }
            }
            if (nrint%2==1)
                sol++;
        }
    }
    fout<<sol<<"\n";

    return 0;
}
