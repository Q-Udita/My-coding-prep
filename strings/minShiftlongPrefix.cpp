#include <iostream>
#include<string>
using namespace std;

int main() {
	string p="geeksforgeeks";
	string t="bgeek";
	int i=i,j=0,n,m,c=0,k=0;
	n=t.length();
	m=p.length();
	vector<int> f(m,0);
	int l=m;
	while(l--) {
	    i=1;j=0;f[0]=0;
	    while(i<l) {
	        if(p[j]==p[i]) {
	            f[i]=j+1;
	            i++;j++;
	        }
	        else if(j>0) 
	            j=f[j-1];
	        else {
	            f[i]=0;
	            i++;
	        }
	    }
	    i=0;j=0;
	    while(i<n) {
	        if(p[j]==t[i]) {
	            if(j==l-1) {
	                c=i-j;
	                k=1;
	                break;
	            }
	       else {  i++;j++; }
	        }
	        else if(j>0) 
	            j=f[j-1];
	        else {
	            
	            i++;
	        }
	    }
	    if(k==1) break;
	}
	cout<<c;
	return 0;
}
