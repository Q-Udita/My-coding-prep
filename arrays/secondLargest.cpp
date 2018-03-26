#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,i;
	cin>>t;
	while(t--) {
	    cin>>n;
	    vector<int> v(n);
	    for(i=0;i<n;i++) {
	        cin>>v[i];
	    }
	    int first=INT_MIN;
	    int second=INT_MIN;
	    for(i=0;i<n;i++) {
	        if(v[i]>second && v[i]<first)
	            second=v[i];
	        else if(v[i]>first) {
	            int temp=first;
	            first=v[i];
	            second=temp;
	        }
	    }
	    if(second==INT_MIN)
	    cout<<-1<<endl;
	    else
	    cout<<second<<endl;
	}
	return 0;
}
