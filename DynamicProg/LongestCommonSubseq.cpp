#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,i,j,count=0,a,b;
	    cin>>n1>>n2;
	    vector<char> s1(n1+1);
	    vector<char> s2(n2+1);
	    for(i=1;i<=n1;i++)
	        cin>>s1[i];
	    for(i=1;i<=n2;i++)
	        cin>>s2[i];
	 
	    vector<vector<int>> v;
	    v.resize(n1+1,vector<int>(n2+1));
	    vector<vector<char>> res;
	    res.resize(n1+1,vector<char>(n2+1));
	    
	    for(i=0;i<=n1;i++)
	        v[i][0]=0;
	    for(i=0;i<=n2;i++)
	        v[0][i]=0;
	    for(i=1;i<=n1;i++)
	    {
	        for(j=1;j<=n2;j++)
	        {
	           if(s1[i]==s2[j])
	               {
	                   v[i][j]=1+v[i-1][j-1];
	                   res[i][j]='c';
	               }
	           else{
	               if(v[i-1][j] > v[i][j-1])
	                {
	                    v[i][j]=v[i-1][j];
	                    res[i][j]='t';
	                }
	               else 
	               {
	                   v[i][j]=v[i][j-1];
	                   res[i][j]='l';
	               }
	           }
	        }
	    }
	    
	  for(i=0;i<=n1;i++)
	  {
	      for(j=0;j<=n2;j++)
	      {
	          if(v[i][j]>count)
	            count=v[i][j];
	      }
	  }
	   i=n1; j=n2; 
	  while(v[i][j]!=0)
	    {
	        if(res[i][j]=='c')
	        {
	            cout<<s1[i];
	            i-=1; j-=1;
	        }
	        else if(res[i][j]=='l')
	            j-=1;
	        else i-=1;
	    }
	    cout<<endl<<count<<endl;
	}
	return 0;
}
