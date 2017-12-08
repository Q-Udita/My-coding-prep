#include <bits/stdc++.h>
#include<vector>
using namespace std;

string isBalanced(string s) {
   
    char c;
    int i;
    
    vector<char> v;
    for(i=0;i<s.length();i++) {
        
        if((s[i]=='{') ||(s[i]=='[')||(s[i]=='('))
            v.push_back(s[i]);
        
        else if(s[i]=='}') {
            if(!v.empty()) {
            c=v.back();
            if(c=='{')
                v.pop_back();
            else return("NO");
            }
            else return("NO");
        }
        
        else if(s[i]==']') {
            if(!v.empty()) {
            c=v.back();
            if(c=='[')
                v.pop_back();
            else return("NO");
            }
            else return("NO");
        }
        
        else if(s[i]==')') {
            if(!v.empty()) {
            c=v.back();
            if(c=='(')
                v.pop_back();
            else return("NO");
            }
        else return("NO");
        }
        
    }
    if(v.empty()) return "YES";
    else return "NO";
        
    }
    


int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}
