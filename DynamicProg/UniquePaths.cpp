class Solution {
public:
    int uniquePaths(int m, int n) {
        int count[100][100];
    int i,j;
    for(i=0;i<m;i++) {
        count[i][0]=1;
    }
    
    for(i=0;i<n;i++) {
        count[0][i]=1;
    }
    
    for(i=1;i<m;i++) {
        for(j=1;j<n;j++) {
            count[i][j]=count[i-1][j]+count[i][j-1];
        }
    }
    
    return count[m-1][n-1];
    }
   
        
};

