#include<bits/stdc++.h>
using namespace std;
void palindrome(vector<char>);
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    vector<char> t(str.size());
	    for(int i=0;i<str.size();i++)
	        t[i]=str[i];
	    palindrome(t);
	    cout<<endl;
	}
	return 0;
}

void palindrome(vector<char> t)
{
    int i,j,k,maxlen=0,start=1,c=0;
    vector<vector<int>> table(t.size(),vector<int> (t.size()));
    for(i=0;i<t.size();i++)
        table[i][i]=1;
    maxlen=1;
    start=0;
    
    for(i=0;i<t.size()-1;i++)
     {
        if(t[i]==t[i+1])
        {
            table[i][i+1]=1;
            maxlen=2;
            if(c==0)
            {
                c=1;
                start=i;
            }
        }
     }
      c=0;  
    for(k=3;k<=t.size();k++)
    {
        for(i=0;i<t.size()-k+1;i++)
        {
            j=i+k-1;
            if(table[i+1][j-1] && t[i]==t[j])
            {
                table[i][j]=1;
                if(k>maxlen && c==0)
                {
                    c=1;
                    maxlen=k;
                    start=i;
                }
            }
        }
        c=0;
    }
    
    for(j=start;j<maxlen+start;j++)
        cout<<t[j];
    
}
