#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,sum=0,k,s=0,t;
	    cin>>n;
	    cin>>k;
	    vector<int> v(n+1);
	    for(i=1;i<=n;i++)
	        cin>>v[i];
        v[0]=0;
        t=1;
        for(i=1;i<=n;i++)
        {
            sum=sum-v[i-1];
            for(j=t;j<=n;j++)
            {
                t=j;
                if(sum+v[j] == k)
                 {
                     s=1;
                     break;
                 }
                else if(sum+v[j]+v[j+1] <= k)
                    sum=sum+v[j];
                else if(sum+v[j]+v[j+1] > k)
                    break;
            }
            if(s==1)
            break;
        }
        if(s==1)
        cout<<i<<" "<<j<<endl;
        else cout<<-1<<endl;
	   
	}
	return 0;
}
