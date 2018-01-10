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

int number_needed(string a, string b) {
   
    vector<int> res(26,0);
    for(int i=0;i<a.length();i++) {
        int p=(int)a[i];
        res[p-97]++;
    }
       for(int i=0;i<b.length();i++) {
           int p=(int)b[i];
        res[p-97]--;
    }
    int sum=0;
    for(int i=0;i<26;i++) {
        sum+=abs(res[i]);
    }
    return sum;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
