#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    vector<int> f(26,0);
    vector<int> F(26,0);
    int i,k=0,c,j;
    int n=magazine.size();
    int m=ransom.size();
    
    for(i=0;i<n;i++) {
        for(j=0;j<magazine[i].size();j++) {
        c=(int)magazine[i][j];
        if(c<91 && c!=32)
            F[c-65]++;
        else f[c-97]++;
        }
    }
     for(i=0;i<m;i++) {
         for(j=0;j<ransom[i].size();j++)  {
         c=(int)ransom[i][j];
        if(c<91 && c!=32)
            F[c-65]--;
        else f[c-97]--;
         }
    }
    for(i=0;i<26;i++) {
        if((F[i] < 0)|| (f[i]<0)) {
            k=1;
            break;
        }    
    }
    if(k==1) return(0);
    else return(1);
    
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
