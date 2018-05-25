#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,sum=0;
	    cin>>n;
	    vector<int> v(n+1);
	    for(i=1;i<=n;i++)
	    {
	        cin>>v[i];
	        sum=sum+v[i];
	    }
	    if(sum%2 != 0)
	        cout<<"NO"<<endl;
	    else {
	        sum=sum/2;
	        vector<vector<int>> ss;
	        ss.resize(n+1,vector<int>(sum+1));
	        for(i=0;i<=n;i++)
	            ss[i][0]=1;
	        for(i=1;i<=sum;i++)
	            ss[0][i]=0;
	        for(i=1;i<=n;i++)
	        {
	            for(j=0;j<=sum;j++)
	            {
	                if(v[i] > j)
	                    ss[i][j]=ss[i-1][j];
	                else 
	                    ss[i][j]= ss[i-1][j] || ss[i-1][j-v[i]];
	            }
	        }
	        cout<<((ss[n][sum]==1)? "YES":"NO")<<endl;
	    }
	       
	}
	return 0;
}
