#include <iostream>
#include <fstream>
#include <vector>

#define pb push_back
using namespace std;
typedef long long ll;
ifstream fin ("day12.in");
ofstream fout ("day12.out");
const ll Nmax=105, Vmax=25;

string s, s2;
vector <ll> v, pos;
//dp[i][j][k] = nr of ways of taking the first i characters of the string, curently be at group j, that currently has k '#'s
ll dp[Nmax][Nmax][Vmax];
ll sum, sol;

int main(){
    while (fin>>s){
        string aux=s;
        for (int i=0; i<4; i++){
            s.pb('?');
            s+=aux;
        }
        s.pb('.');
        ll n=s.size();

        // get the numbers
        fin>>s2;
        ll j=0;
        while (j<s2.size()){
            ll nr=0;
            while (j<s2.size() && s2[j]!=','){
                nr=nr*10+s2[j]-'0';
                j++;
            }
            v.pb(nr);
            j++;
        }
        ll m=v.size();
        for (ll i=0; i<4; i++)
            for (ll j=0; j<m; j++)
                v.pb(v[j]);
        m=v.size();

        ll sum=0, sumant=0;
        dp[0][1][0]=1;
        for (ll i=1; i<=n; i++){
            sum=0;
            if (s[i-1]=='#' || s[i-1]=='?'){
                for (ll j=1; j<=m; j++)
                    for (ll k=1; k<=v[j-1]; k++)
                        dp[i][j][k]+=dp[i-1][j][k-1];
            }
            if (s[i-1]=='.' || s[i-1]=='?'){
                for (ll j=1; j<=m; j++){
                    dp[i][j][0]+=dp[i-1][j][0];
                    if (j>=2)
                        dp[i][j][0]+=dp[i-1][j-1][v[j-2]];
                }
                sum=sumant+dp[i-1][m][v[m-1]];
            }
            sumant=sum;
        }
        sol+=sum;

        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=m; j++)
                for (ll k=0; k<=v[m-1]; k++)
                    dp[i][j][k]=0;
        v.clear(); pos.clear();
    }
    fout<<sol<<'\n';

    return 0;
}
