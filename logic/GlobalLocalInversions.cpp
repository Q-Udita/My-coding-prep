class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_map<char,int> l;
        int i,c=0;
        int s1=J.size();
        int s2=S.size();
        for(i=0;i<s1;i++) {
            l[J[i]]++;
        }
        for(i=0;i<s2;i++) {
            if(l[S[i]]) 
                c++;
        }
        return c;
    }
};
