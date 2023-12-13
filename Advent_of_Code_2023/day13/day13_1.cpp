#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define pb push_back
using namespace std;
ifstream fin ("day13.in");
ofstream fout ("day13.out");

string s;
vector<string> mat;
int sol, sum;

int main(){
    while (fin>>s){
        fin.get();
        sum=0;
        mat.clear();
        while (!s.empty()){
            mat.pb(s);
            getline(fin, s);
            if (!fin)
                break;
        }
        int n=mat.size(), m=mat[0].size();
        for (int i=0; i<n-1; i++){ //reflexie pe linii
            int d=0;
            bool ok=1;
            while (i-d>=0 && i+d+1<n && ok){
                for (int j=0; j<m; j++)
                    if (mat[i-d][j]!=mat[i+d+1][j])
                        ok=0;
                d++;
            }
            if (ok)
                sum+=100*(i+1);
        }
        for (int j=0; j<m-1; j++){ //reflexie pe coloane
            int d=0;
            bool ok=1;
            while (j-d>=0 && j+d+1<m && ok){
                for (int i=0; i<n; i++)
                    if (mat[i][j-d]!=mat[i][j+d+1])
                        ok=0;
                d++;
            }
            if (ok)
                sum+=j+1;
        }
        sol+=sum;
    }
    fout<<sol;
}
