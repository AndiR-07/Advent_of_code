#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define eb emplace_back
#define pb push_back
using namespace std;
const int Vmax=1000;
ifstream fin("day22.in");
ofstream fout("day22.out");

struct brick{
    int x1, y1, z1;
    int x2, y2, z2;
};
vector<brick> v;
string s;
int i, sol;
int mat[Vmax][Vmax], type[Vmax][Vmax];
vector<bool> ad;
unordered_set<int> crt;

inline int get_nr(){
    int nr=0;
    while (i<s.size() && s[i]!=',' && s[i]!='~'){
        nr=nr*10+s[i]-'0';
        i++;
    }
    i++;
    return nr;
}
bool cmp(brick a, brick b){
    return a.z1<b.z1;
}

int main (){
    for (int i=0; i<Vmax; i++)
        for (int j=0; j<Vmax; j++)
            type[i][j]=-1;

    while (fin>>s){
        i=0;
        v.eb();
        v.back().x1=get_nr();
        v.back().y1=get_nr();
        v.back().z1=get_nr();

        v.back().x2=get_nr();
        v.back().y2=get_nr();
        v.back().z2=get_nr();

        if (v.back().x1>v.back().x2) 
            swap(v.back().x1, v.back().x2);
        else if (v.back().y1>v.back().y2) 
            swap(v.back().y1, v.back().y2);
        else if (v.back().z1>v.back().z2) 
            swap(v.back().z1, v.back().z2);
    }
    sort(v.begin(), v.end(), cmp);
    ad.resize(v.size());
    for (int i=0; i<v.size(); i++){
        crt.clear();
        int mx=0;
        for (int l=v[i].x1; l<=v[i].x2; l++)
            for (int c=v[i].y1; c<=v[i].y2; c++){
                if (mx<mat[l][c]){
                    crt.clear();
                    if (type[l][c]!=-1)
                        crt.insert(type[l][c]);
                    mx=mat[l][c];
                }
                else if (mx==mat[l][c] && type[l][c]!=-1)
                    crt.insert(type[l][c]);
            }
        int dif=v[i].z1-mx-1;
        v[i].z1-=dif; 
        v[i].z2-=dif;
        for (int l=v[i].x1; l<=v[i].x2; l++)
            for (int c=v[i].y1; c<=v[i].y2; c++){
                mat[l][c]=v[i].z2;
                type[l][c]=i;
            }
        if (crt.size()==1)
            ad[*crt.begin()]=1;
    }
    for (int i=0; i<ad.size(); i++)
        if (!ad[i])
            sol++;
    fout<<sol;

    return 0;
}
