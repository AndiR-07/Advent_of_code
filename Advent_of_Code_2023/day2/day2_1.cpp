#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("day2.in");
ofstream fout ("day2.out");

string s;
long long i, sum;
int v[3], mx[3];
int get_nr(string &s){
    int nr=0;
    for (int i=0; i<s.size(); i++)
        nr=nr*10+s[i]-'0';
    return nr;
}

int main(){
    fin>>s;
    while (fin>>s){
        i++;
        while (fin>>s && s[0]!='G'){
            int nr=get_nr(s);
            fin>>s;
            if (s[0]=='r')
                v[0]+=nr;
            else if (s[0]=='g')
                v[1]+=nr;
            else v[2]+=nr;

            if (s[s.size()-1]!=','){
                for (int i=0; i<3; i++)
                    if (v[i]>mx[i])
                        mx[i]=v[i];
                v[0]=v[1]=v[2]=0;
            }
        }
        long long p=mx[0]*mx[1]*mx[2];
        sum+=p;

        mx[0]=mx[1]=mx[2]=0;
    }
    fout<<sum;

    return 0;
}
