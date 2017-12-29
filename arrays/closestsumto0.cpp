#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int t,n,i,num1,num2,num3,num4,l=0;;
	cin>>t;
	while(t--) {
	    l=0;
	    cin>>n;
	    vector<int> v(n);
	    for(i=0;i<n;i++) {
	        cin>>v[i];
	    }
	    sort(v.begin(),v.end());
	    int j=0,k=n-1;
	    int sum,possum=LONG_MAX,negsum=LONG_MIN;
	    while(j<k) {
	       sum=v[j]+v[k];
	       if(sum>0) {
	           if(sum<possum) {
	               possum=sum;
	               num1=j;
	               num2=k;
	               k--;
	           }
	       }
	       else if(sum<0){
	           if(sum>negsum) {
	               negsum=sum;
	               num3=j;
	               num4=k;
	               j++;
	           }
	       }
	       else {
	           cout<<v[j]<<" "<<v[k]<<endl;
	           l=1; break;
	       }
	    }
	    
	    if(l==0) {
	    if(possum<abs(negsum))
	     cout<<v[num1]<<" "<<v[num2]<<endl;
	    else cout<<v[num3]<<" "<<v[num4]<<endl; 
	    }
	}
	return 0;
}

