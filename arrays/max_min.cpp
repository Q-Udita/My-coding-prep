#include <bits/stdc++.h>
using namespace std;
void min_max(vector<int> v,int l,int n,int &max,int &min) {
    if(n==l)
        max=min=v[l];
    else if((n+1)==2) {
        if(v[l]>v[n]) {
            max=v[l];
            min=v[n];
        }
        else {
            max=v[n];
            min=v[l];
        }
    }
    else {
        int m=(l+n)/2;
        int max1=max,max2=max,min1=min,min2=min;
        min_max(v,l,m,max1,min1);
        min_max(v,m+1,n,max2,min2);
        max=(max1>max2)? max1:max2;
        min=(min1<min2)? min1:min2;
        
    }
}
int main()
{
    int n,i,min,max;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    min_max(v,0,n-1,max,min);
    cout<<max<<" "<<min;
    
    return 0;
}
