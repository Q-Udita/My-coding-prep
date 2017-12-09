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


int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
    }
    
    vector<int> sum1(n1);
    sum1[h1.size()-1]=h1[h1.size()-1];
    for(int l=h1.size()-2;l>=0;l--) {
        sum1[l]=h1[l]+sum1[l+1];
    }
    
    vector<int> sum2(n2);
    sum2[h2.size()-1]=h2[h2.size()-1];
    for(int l=h2.size()-2;l>=0;l--) {
        sum2[l]=h2[l]+sum2[l+1];
    }
    
    vector<int> sum3(n3);
    sum3[h3.size()-1]=h3[h3.size()-1];
    for(int l=h3.size()-2;l>=0;l--) {
        sum3[l]=h3[l]+sum3[l+1];
    }
    
    int col1=0;
    int col2=0;
    int col3=0;
    while(sum1[col1]!=sum2[col2] || sum2[col2]!=sum3[col3]) {
        if(sum1[col1]>sum2[col2] || sum1[col1]>sum3[col3])
            col1++;
        else if(sum2[col2]>sum1[col1] || sum2[col2]>sum3[col3])
            col2++;
        else if(sum3[col3]>sum1[col1] || sum3[col3]>sum2[col2])
            col3++;
    }
    
    cout<<sum1[col1]<<endl;
    
    
    return 0;
}
