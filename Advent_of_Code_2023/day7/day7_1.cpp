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
    /// five of a kind
    for (ll i=0; i<13; i++)
        if (fr[i]==5)
            return 6;
    ///four of a kind
    for (ll i=0; i<13; i++)
        if (fr[i]==4)
            return 5;
    ///full house
    bool ok2=0, ok3=0;
    for (ll i=0; i<13; i++)
        if (fr[i]==2)
            ok2=1;
        else if (fr[i]==3)
            ok3=1;
    if (ok2 && ok3)
        return 4;
    ///three of a kind
    for (ll i=0; i<13; i++)
        if (fr[i]==3)
            return 3;
    ///two pair
    int t=0;
    for (ll i=0; i<13; i++)
        if (fr[i]==2)
            t++;
    if (t==2)
        return 2;
    ///one pair
    for (ll i=0; i<13; i++)
        if (fr[i]==2)
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
    for (ll i='2'; i<='9'; i++)
        cards[i-'0'-2]=i;
    cards[8]='T'; cards[9]='J';
    cards[10]='Q'; cards[11]='K';
    cards[12]='A';
    for (ll i=0; i<13; i++)
        cnv[cards[i]]=i;

    ll i=0;
    while (fin>>v[i].s){
        fin>>v[i].val;
        v[i].score=get_score(v[i].s);
        i++;
    }

    sort(v, v+i, cmp);
    ll sol=0;
    for (ll j=0; j<i; j++)
        sol+=(j+1)*v[j].val;
    fout<<sol;

    return 0;
}
