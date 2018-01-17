/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    int c=0,l=k-1,count=0,i;
    vector<int> d(105,0);
    while(c<=n-k && l<n) {
        count=0;
        for(i=c;i<=l;i++) {
            d[A[i]]++;
            if(d[A[i]]==1) count++;
        }
        cout<<count<<" ";
        c++;l++;
        fill(d.begin(),d.end(),0);
    }
}
