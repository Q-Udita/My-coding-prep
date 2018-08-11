#include<bits/stdc++.h>
using namespace std;

vector<int> Csort(vector<int>);
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int n,i;
	    cin>>n;
	    vector<int> v(n);
	    for(i=0;i<n;i++)
	        cin>>v[i];
	    vector<int> v1(n);
	    v1=Csort(v);
	    for(i=0;i<n;i++)
	        cout<<v1[i]<<" ";
	    cout<<endl;
	}
	return 0;
}

vector<int> Csort(vector<int> v) {
    
    int low,mid,high,a;
    low=mid=0;
    high=v.size()-1;
    while(mid<=high) {
        int ch=v[mid];
        switch(ch) {
            
            case 0:
            a=v[low];
            v[low]=v[mid];
            v[mid]=a;
            low++;
            mid++;
            break;
            
            case 1:
            mid++;
            break;
            
            case 2:
            a=v[mid];
            v[mid]=v[high];
            v[high]=a;
            high--;
            break;
        }
    }
    return v;
}
