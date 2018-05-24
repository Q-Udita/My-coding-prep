#include<bits/stdc++.h>
using namespace std;
int max(int,int);
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,W,i,j;
	    cin>>n;
	    cin>>W;
	    vector<int> v(n+1);
	    vector<int> wt(n+1);
	    for(i=1;i<=n;i++)
	        cin>>v[i];
	    for(i=1;i<=n;i++)
	        cin>>wt[i];
	    vector<vector<int>> g;
	    g.resize(n+1,vector<int>(W+1));
	    
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=W;j++)
	        {
	            if(j==0 || i==0)
	                g[i][j]=0;
	            else if(wt[i]<=j)
                {
                    g[i][j]=max(g[i-1][j] , v[i]+g[i-1][j-wt[i]]);
                }
                else g[i][j]=g[i-1][j];
	        }
	    }
	    int max=0;
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=W;j++)
	        {
	            if(g[i][j]>max)
	                max=g[i][j];
	        }
	    }
	    cout<<max<<endl;
	}
	return 0;
}

int max(int a,int b)
{
    return((a>b)? a:b);
}
