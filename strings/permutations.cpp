using namespace std;
void permutate(vector<char> s);
void permutateUtil(vector<char>,vector<int>,vector<char>,int);
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    vector<string> s(1);
	    cin>>s[0];
	    int n=s[0].length();
	    vector<char> s1(n);
	    for(int i=0;i<n;i++)
	        s1[i]=s[0][i];
	    permutate(s1);
	    cout<<endl;
	}
	return 0;
}

void permutate(vector<char> s) 
{
 
    unordered_map<char,int> h;
    int i,j,k=0;
    for(i=0;i<s.size();i++)
    {
        if(h[s[i]]==NULL)
           { h[s[i]]=1;k++;}
        else h[s[i]]++;
    }
   
    vector<char> str(k);
    vector<int> count(k);
    k=0;
    for(i=65;i<=90;i++)
    {
        for(j=0;j<s.size();j++)
        {
            if(s[j]==(char)i)
            {
                str[k]=s[j];
                count[k]=h[s[j]];
                k++;
                break;
            }
        }
    }
    vector<char> result(s.size());
    permutateUtil(str,count,result,0);
}

void permutateUtil(vector<char> str,vector<int> count,vector<char> result,int level)
{
    int i;
    if(level == result.size())
    {
        for(i=0;i<result.size();i++)
            cout<<result[i];
        cout<<" ";
        return;
    }
    else 
    {
        for(i=0;i<str.size();i++)
        {
            if(count[i]==0)
                continue;
            result[level]=str[i];
            count[i]--;
            permutateUtil(str,count,result,level+1);
            count[i]++;
        }
    }
}
