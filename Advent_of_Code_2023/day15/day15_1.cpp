#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("day15.in");
ofstream fout ("day15.out");
const int B=17, Mod=256;

string s;
int sol;

int main(){
    fin>>s;
    int i=0;
    while (i<s.size()){
        int sum=0;
        while (i<s.size() && s[i]!=','){
            sum=(sum+s[i])*B%Mod;
            i++;
        }
        sol+=sum;
        i++;
    }
    fout<<sol;

    return 0;
}
