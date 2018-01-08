class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int i,d,best=K,c=0;
        while(V--) {
           
        for(d=-1;d<=1;d+=2) {
         i=K,best=K,c=0;
            while(i+d>=0 && i+d<heights.size() && heights[i+d]<=heights[i]) {
                if(heights[i+d]<heights[i]) {
                    best=i+d;
                } 
                i+=d;
            }
            if(heights[best]<heights[K]) {
                heights[best]++;
                c=1;
                break;
            }
        }
        if(c==0)
            heights[K]++;
        }
        return heights;
    }
};
