#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,k,l;
	    cin>>n;
	    vector<int> v(n);
	    for(i=0;i<n;i++)
	        cin>>v[i];
	    sort(v.begin(),v.end());
	    int m=INT_MAX;
	    i=0;j=n-1;
	    while(i<j)
	    {
	        int temp=v[i]+v[j];
	        if(abs(temp) < abs(m))
	        {
	            m=temp;
	            k=i;
	            l=j;
	        }
	        if(temp<0)
	        i++;
	        else j--;
	    }
	    cout<<v[k]<<" "<<v[l]<<endl;
	}
	return 0;
}
