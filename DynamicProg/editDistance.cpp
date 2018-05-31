#include<bits/stdc++.h>
using namespace std;
int min(int,int,int);
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,i,j;
	    cin>>n1>>n2;
	    vector<char> s1(n1+1);
	    vector<char> s2(n2+1);
      
	    for(i=1;i<=n1;i++)
	       cin>>s1[i];
	    for(j=1;j<=n2;j++)
	        cin>>s2[j];
          
	    vector<vector<int>> ed;
	    ed.resize(n1+1,vector<int>(n2+1));
      
	    for(i=1;i<=n1;i++)
	        ed[i][0]=i;
        for(i=1;i<=n2;i++)
            ed[0][i]=i;
	    ed[0][0]=0;
	    for(i=1;i<=n1;i++)
	    {
	        for(j=1;j<=n2;j++)
	        {
	            int p,q,r;
	            if(s1[i]==s2[j])
	                ed[i][j]=ed[i-1][j-1];
	            else
	            {
	                ed[i][j]=1+min(ed[i-1][j-1],ed[i-1][j],ed[i][j-1]);
	            }
	        }
	    }
	    cout<<ed[n1][n2]<<endl;
	}
	return 0;
}

int min(int a, int b, int c)
{
    int min;
    min=(a<b)? (a<c)?a:c : (b<c)?b:c;
    return min;
}
