#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int i,j,n,k;
	    cin>>n;
	    vector<int> v(n);
	    for(i=0;i<n;i++)
	        cin>>v[i];
	    cin>>k;
	    vector<int> cc(k+1,0);
	    cc[0]=1;
	    for(i=0;i<n;i++)
	        for(j=v[i];j<=k;j++)
	            cc[j]+=cc[j-v[i]];
	    cout<<cc[k]<<endl;
	}
	return 0;
}
