#include<bits/stdc++.h>
using namespace std;
int max(int,int);
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,i,j,min,x;
	    cin>>n>>k;
	    vector<vector<int>> e;
	    e.resize(n+1,vector<int>(k+1));
	    for(i=1;i<=n;i++)
	    {
	        e[i][0]=0;
	        e[i][1]=1;
	    }
	   
	    for(i=1;i<=k;i++)
	        e[1][i]=i;
	        
	    for(i=2;i<=n;i++)
	    {
	        for(j=2;j<=k;j++)
	        {
	            min=INT_MAX;
	            for(x=1;x<=j;x++)
	            {
	                int p=max(e[i-1][x-1] , e[i][j-x]);
	                if(p<min)
	                    min=p;
	            }
	            e[i][j]=1+min;
	        }
	    }
	    cout<<e[n][k]<<endl;
	}
	return 0;
}

int max(int a,int b)
{
    return (a>b)? a:b;
}
