#include <iostream>
#include <fstream>
#include <algorithm>

#define fi first
#define se second
using namespace std;
ifstream fin ("day7.in");
ofstream fout ("day7.out");
typedef long long ll;
const ll Nmax=1e3+5;

ll cnv[256];
char cards[13];
struct hand{
    ll val, score;
    string s;
}v[Nmax];

ll get_score(string s){
    ll fr[13]={};
    for (ll i=0; i<5; i++)
        fr[cnv[s[i]]]++;
    ll mx=0, mx2=0;
    for (ll i=1; i<13; i++)
        if (fr[i]>mx){
            mx2=mx;
            mx=fr[i];
        }
        else mx2=max(mx2, fr[i]);
    /// five of a kind
    if (mx+fr[0]==5)
        return 6;
    ///four of a kind
    if (mx+fr[0]==4)
        return 5;
    ///full house
    if(mx+mx2+fr[0]==5)
        return 4;
    ///three of a kind
    if (mx+fr[0]==3)
        return 3;
    ///two pair
    if (mx+mx2+fr[0]==4)
        return 2;
    ///one pair
    if (mx+fr[0]==2)
        return 1;
    ///high card
    return 0;
}
bool cmp(hand a, hand b){
    if (a.score!=b.score)
        return a.score<b.score;
    for (ll i=0; i<5; i++)
        if (cnv[a.s[i]]!=cnv[b.s[i]])
            return cnv[a.s[i]]<cnv[b.s[i]];
    return 1;
}
int main()
{
    cards[0]='J';
    for (ll i='2'; i<='9'; i++)
        cards[i-'0'-1]=i;
    cards[9]='T'; cards[10]='Q';
    cards[11]='K'; cards[12]='A';
    for (ll i=0; i<13; i++){
        cnv[cards[i]]=i;
    }

    ll i=0;
    while (fin>>v[i].s){
        fin>>v[i].val;
        v[i].score=get_score(v[i].s);
        i++;
    }

    sort(v, v+i, cmp);
    ll sol=0;
    for (ll j=0; j<i; j++){
        sol+=(j+1)*v[j].val;
        //cout<<v[j].s<<' '<<v[j].score<<'\n';
    }
    fout<<sol;

    return 0;
}
