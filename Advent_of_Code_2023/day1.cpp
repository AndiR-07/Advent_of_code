#include <fstream>
#include <iostream>

using namespace std;
ifstream fin ("day1.in");
ofstream fout ("day1.out");

string s;

struct digit{
    string s;
    int val;
}v[9]={{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int main(){
    int sol=0;
    while (fin>>s){
        int f=-1, l=-1, i=0, d;
       for (int i=0; i<s.size(); i++){
            d=-1;
            if ('0'<=s[i] && s[i]<='9')
                d=s[i]-'0';
            else{
                for (int j=0; j<9; j++)
                    if (i+v[j].s.size()<=s.size()){
                        bool ok=1;
                        for (int k=0; k<v[j].s.size(); k++)
                            if (v[j].s[k]!=s[i+k]){
                                ok=0;
                                break;
                            }
                        if (ok){
                            d=v[j].val;
                            break;
                        }
                    }
            }
            if (d!=-1){
                if (f==-1)
                    f=d;
                l=d;
            }
        }
        sol+=f*10+l;
    }
    fout<<sol;
}
