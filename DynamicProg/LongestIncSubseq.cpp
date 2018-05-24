#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,max=0;
	    cin>>n;
	    vector<int> v(n);
	    vector<int> r(n);
	    for(i=0;i<n;i++)
	     {
	         cin>>v[i];
	         r[i]=1;
	     }
	     for(i=0;i<n;i++)
	     {
	         for(j=0;j<=i;j++)
	         {
	             if(v[j]<v[i] && r[j]+1>r[i])
	                r[i]=r[j]+1;
	         }
	     }
	     for(i=0;i<n;i++)
	     {
	         if(r[i]>max)
	            max=r[i];
	     }
	     cout<<max<<endl;
	}
	return 0;
}
